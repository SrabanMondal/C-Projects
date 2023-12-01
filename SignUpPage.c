#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int day()
{   
    int d;
    printf("DAY-");
    scanf("%d",&d);
    if((d>=0)&&(d<=30))
    {
        return d;
    }
    else
    {
        printf("Wrong day\n");
        return day();
    }
}
int month()
{   
    int d;
    printf("MONTH-");
    scanf("%d",&d);
    if((d>=0)&&(d<=12))
    {
        return d;
    }
    else
    {
        printf("Wrong month\n");
        return month();
    }
}
int year()
{   
    int d;
    printf("YEAR-");
    scanf("%d",&d);
    if((d>=1920)&&(d<=2018))
    {
        return d;
    }
    else
    {
        printf("Wrong year\n");
        return year();
    }
}
void email(char *a, char c[])
{
    
    strcat(a,c);
    for(int i=0; a[i]!='\0';i++)
    {
        a[i]=tolower(a[i]);
    }
}
int check(char a[], int l)
{
    int i,low,upp,digit,pun;
    for(i=0;i<l;i++)
    {
        if(isalpha(a[i])!=0)
        {
            if(islower(a[i])==0)
            {
                upp++;
            }
            else
            {
                low++;
            }
        }
        if(isdigit(a[i])!=0)
        {
            digit++;
        }
        if(ispunct(a[i])!=0)
        {
            pun++;
        }
    }
    if(upp==0||low==0||digit==0||pun==0)
    {
        printf("\nPassword too weak\nRe-Enter password-");
        scanf("%s",a);
        l=strlen(a);
        l=check(a,l);
        return l;
    }
    else
    {
        printf("Good password");
        return l;
    }
}
void main()
{
    system("cls");
    char f[10],l[10],g[10];
    int d,m,y,ch;
    printf("\t\t\tTHIS IS SAMPLE SIGN UP PAGE\n\t\t\t\tGOOGLE\nCreate a Google Account\n\t\tEnter your name");
    printf("\nFirst Name-"); scanf("%s",f);
    printf("\nLast Name-"); scanf("%s",l);
    getch();
    system("cls");
    printf("\t\t\tBasic Information\tEnter your date of birth-\n");
    d=day(); m=month(); y=year();
    printf("Choose your gender-\n1.Female\n2.Male\n3.Rather not say\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        strcpy(g,"Female");
        break;
        case 2:
        strcpy(g,"Male");
        break;
        case 3:
        strcpy(g,"Unknown");
        break;
        default:
        printf("Wrong Choice");
    }
    getch();
    system("cls");
    printf("\t\t\tChoose your Gmail address\nPick a gmail address or create your own\n");
    char name[4][45], end[11]={"@gmail.com"};
    strcpy(name[0],f);
    strcpy(name[2],f);
    strcpy(name[1],l); 
    strcat(name[2],l);
    for(int i=0;i<3;i++)
    {
        email(name[i] , end);
    }
    printf(" 1.%s\n 2.%s\n 3.%s\n 4.Custom\n",name[0],name[1],name[2]);
    scanf("%d",&ch);
    if (ch==4)
    {
        printf("Enter gmail address-");
        scanf("%s",name[3]);
        email(name[3],end);
    }
    getch();
    system("cls");
    char pw[20];
    int len;
    printf("\t\t\tCreate your password");
    printf("\nEnter a strong password containing atleast one upper case, one lower case, one special character, one digit and minimum of 8 characters\n");
    scanf("%s",pw);
    len=strlen(pw);
    len=check(pw, len);
    getch();
    system("cls");
    printf("\t\t\tYOUR PROFILE\n");
    printf("Name-%s %s\n",f,l);
    printf("Age-%d\n",2023-y);
    printf("Gender-%s\n",g);
    printf("Gmail address-%s",name[ch-1]);
}