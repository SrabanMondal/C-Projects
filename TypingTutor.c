//Try to beat this, if you are good typer
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

char *easy[5]={"The quick brown fox jumps over the lazy dog","Pack my box with five dozen liquor jugs","Moonlit paths beckon wanderers","Library whispers hold stories","Silent stars tell tales"};
char *medium[5]={"Procrastination is the thief of time; tackle it head-on","Serendipitous juxtapositions unravel cosmic mysteries","Adventurous travelers embarked on a quest to uncover the hidden treasures buried deep within the heart of the mystical forest","The ancient castle stood atop the misty hill, shrouded in tales of bygone eras and whispered secrets","Ephemeral moments linger in memory"};
char *hard[5]={"Amidst the turbulent tempest of temporal flux, elusive moments crystallize into memories, each a fragment of existence imbued with the essence of transient beauty","Beneath the moonlit sky, a solitary figure strolled along the deserted beach, lost in contemplation","The labyrinthine labyrinth of labyrinthine labyrinths is a perplexing enigma, wherein convoluted corridors conspire to confound even the most adept navigators","The elusive phoenix soared through the ethereal twilight, leaving a trail of luminescent embers in its wake","Esoteric glyphs unveil cosmic mysteries in the quantum tapestry, entwining ephemeral echoes of the unseen symphony."};

void screen();
void tutor(char *test,int i,int q);
void game(int i,int q);

void screen()
{
    printf("This is a typing tutor\n\nINSTRUCTIONS--");
    printf("\n>You will see some lines on screen, you have to type them as fast as possible then press Enter key");
    printf("\n>It will show your accuracy and time taken");
    printf("\n>You can retry to improve ur speed and accuracy");
    printf("\n>If your accuracy and speed is above required value, you can move to next question");
    printf("\n>There are 3 levels-Easy-Medium-Hard");
    printf("\n>You will start from easy difficulty");
    printf("\n>If you fail, you will have to start again");
    printf("\n>Best of luck for beating hard difficulty");
    printf("\n>Press any key to continue the game...");
    getch();
    tutor(easy[0],1,0);
}
void tutor(char *test,int i,int q)
{
    fflush(stdin);
    system("cls");
    printf("Difficulty-");
    i==1?printf("Easy"):i==2?printf("Medium"):printf("Hard");
    clock_t start,end;
    int l,c=0;
    l=strlen(test);
    char ans[l+1];
    start=clock();
    printf("\n%s\n",test);
    scanf("%[^\n]s",ans);
    fflush(stdin);
    end=clock();
    for(int i=0;test[i]!='\0';i++)
    {
        if(test[i]==ans[i])
        {
            c++;
        }
    }
    int a=c==l;
    float t=((double)end-(double)start)/CLOCKS_PER_SEC;
    float p=l/3;
    printf("Required time-%.2f\n",p);
    a==1?printf("Accurate"):printf("Low accuracy");
    printf("\nTime taken %.2f",t);
    if((a==1)&&(t<p))
    {
        printf("\nPass"); int d;
        printf("\nChoose-\n1.Retry\n2.Next\n");
        scanf("%d",&d);
        printf("\nPress any key, when you ready...");
        getch();
        switch(d)
        {
            case 1:
            tutor(test,i,q); break;
            case 2:
            game(i,q); break;
        }
    }
    else
    {
        printf("\nNeed improvement\nSorry, You need to restart.");
        printf("\nPress any key, when you ready...");
        getch();
        tutor(easy[0],1,0);
    }
}
void game(int i,int q)
{
    if(q==4){ i++; q=-1;}
    if(i==4)
    {
        printf("\nYou have beat the game.\nCongrats");
        exit(0);
    }
    else
    {
        q++;
        switch(i)
        {
            case 1: tutor(easy[q],i,q); break;
            case 2: tutor(medium[q],i,q); break;
            case 3: tutor(hard[q],i,q); break;
        }
    }
}
void main()
{
    screen();
}