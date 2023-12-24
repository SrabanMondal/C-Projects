#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
int l;
char app[10][20]={"google","youtube","instagram","facebook","twitter","tinder","snapchat","pininterest","whatsapp","telegram"};

void display(int n,char ch, char word[10]);
void screen();

void screen()
{
    system("cls");
    printf("This is Hangman game-");
    printf("\nDescription :\n");
    printf("1.You have to guess the correct word\n2.You can have atmost 7 wrong guesses\n3.Words are related to famous apps");
    printf("\nEnter any key to start game-");
    getch();
}
void word()
{
    int i,j;
    srand(time(0));
    i=rand()%9;
    l=strlen(app[i]);
    char word[15];
    for(j=0;j<l;j++)
    {
        word[j]='-';
    }
    word[l]='\0';
    int count=0,n=0; char c='\0';
    display(n,c,word);
    while(n<8)
    {
        printf("\nType letter-");
        scanf("%c",&c);
        getchar();
        count=0;
    for(int k=0;k<l;k++)
    {
        if(app[i][k]==c)
        {
            word[k]=app[i][k];
            count++;
        }
    }
        if(count!=0)
        {
            c='\0';
            display(n,c,word);
        }
        else
        {
            n++;
            display(n,c,word);
        }
        if(strcmp(word,app[i])==0)
        {
            printf("Congrats, You guessed correctly.");
            exit(0);
        }
    }
    printf("You lost.\nCorrect word is %s",app[i]);
}

void display(int n,char ch, char word[10])
{
    system("cls");
    char c[8];
    if(ch!='\0') c[n-1]=ch;
    char stick[]={'|','(',')','/','|','\\','/','\\'};
    char body[]={' ',' ',' ',' ',' ',' ',' ',' '};
    if(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            body[i]=stick[i];
        }
    }
    printf("\n___________\n");
    printf("|       %c\n",body[0]);
    printf("|      %c %c\n",body[1],body[2]);
    printf("|      %c%c%c\n",body[3],body[4],body[5]);
    printf("|      %c %c\n",body[6],body[7]);
    printf("\n\nIncorrect guesses-");
    if(n!=0)
    {
    for(int j=0;j<n;j++)
    {
        printf("%c",c[j]);
    }
    }
    printf("\nWord : ");
    puts(word);
}
void main()
{
    screen();
    word();
}
