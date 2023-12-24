#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

char month[12][6]={"JAN","FEB","MARCH","APRIL","MAY","JUNE","JULY","AUG","SEP","OCT","NOV","DEC"};
char day[7][6]={"Mon","Tues","Wed","Thrus","Fri","Sat","Sun"};
void timeprint();
void screen();
int days(int n,int y);
void arrow(int f,int e,int m,int y);
void printmon(int w,int m,int y);
void display();
void back(int w,int m,int y);
void up(int w,int m,int y);
void down(int w,int m,int y);

int days(int n,int y)
{
    switch(n)
    {
        case 1:
        return 31;
        case 2:
        if(y%4==0) return 29;
        else return 28;
        case 3:
        return 31;
        case 4:
        return 30;
        case 5:
        return 31;
        case 6:
        return 30;
        case 7:
        return 31;
        case 8:
        return 31;
        case 9:
        return 30;
        case 10:
        return 31;
        case 11:
        return 30;
        case 12:
        return 31;
    }
}
void screen()
{
    system("cls");
    printf("THIS IS A CALENDER PLANNER");
    printf("\nInstructions\n");
    printf("1.Use right and left arrow keys to navigate between months\n");
    printf("1.Use up and down arrow keys to navigate between years\n");
    printf("4.Tap any other key to exit\n");
    printf("Press any key to see calender\n");
    getch();
    display();
}
void timeprint()
{
    time_t t=time(NULL);
    printf("%s\n",ctime(&t));
}

void arrow(int f,int e,int m,int y)
{
    int c1,c2;
    printf("Press any key--");
    c1=getch();
    if(c1==0xE0)
    {
        c2=getch();
        switch(c2)
        {
            case 75:
            m--;
            if(m==-1)
            {
                m=11; y--;
            }
            back(f,m,y); break;
            case 77:
            m++;
            if(m==12)
            {
                m=0; y++;
            }
            printmon(e,m,y); break;
            case 72:
            y++;
            up(f,m,y); break;
            case 80:
            y--;
            down(f,m,y); break;
        }
    }
}

void printmon(int w,int m,int y)
{
    system("cls");
    timeprint();
    if(m==12) exit(0);
    int q;
    printf("\n\t\t\t%s %d\n\n",month[m],y);
    for(int f=0;f<7;f++)
    {
        printf("%s\t",day[f]);
    }
    printf("\n");
    int k=w; int l=1;
    int i,j;
    i=w;
    q=days(m+1,y);
    q++;
    while(l<q)
    {
        for(j=1;j<8&&l<q;j++)
        {
            if(j<k)
            {
                printf("\t");
            }
            else
            {
            printf("%d\t",l);
            l++;
            }
        }
            k=0;
        printf("\n");
    }
    arrow(i,j,m,y);
}

void display()
{
    time_t t=time(NULL);
    struct tm *tp;
    tp=localtime(&t);
    int y,m,d,w;
    y=tp->tm_year+1900;
    m=tp->tm_mon;
    d=tp->tm_mday;
    w=tp->tm_wday;
    if(w==0) w=7;
    while(d>1)
    {
        w--;
        d--;
        if(w==0) w=7;
    }
    printmon(w,m,y);
}

void back(int w,int m,int y)
{
    w--;
    int d=days(m+1,y);
    if(w==0) w=7;
    while(d>1)
    {
        w--;
        d--;
        if(w==0) w=7;
    }
    printmon(w,m,y);
}
void up(int w,int m,int y)
{
    int d; int i=y-1;
    if(m>1)
    {
    if(y%4==0) d=366;
    else d=365;
    }
    else
    {
        if(i%4==0) d=366;
        else d=365;
    }
    while(d>0) //next year
    {
        w++;
        d--;
        if(w==8) w=1;
    }
    printmon(w,m,y);
}

void down(int w,int m,int y)
{
    int d; int i=y+1;
    if(m>1)
    {
    if(i%4==0) d=366;
    else d=365;
    }
    else
    {
        if(y%4==0) d=366;
        else d=365;
    }
    while(d>0) //back year
    {
        w--;
        d--;
        if(w==0) w=7;
    }
    printmon(w,m,y);
}
void main()
{
    screen();
}