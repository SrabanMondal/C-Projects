#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

char a[3][3];

void screen();
void start();
void computer();
void friend();
void board(char a[3][3]);
void user(char a[3][3]);
void user2(char a[3][3]);
void comp(char a[3][3]);
void input(char a[3][3],int x, int y, int n);
void check(char a[3][3]);
void result(char n);
void pos(char a[3][3], int g);
void data(char a[3][3] ,int n,int m,int o);
void compinput(char a[3][3], int n);

void board(char a[3][3])
{
    system("cls");
    int i,j;
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("| %c |",a[i][j]);
        }
    printf("\n");
    }
}
void screen()
{
    int ch;
    system("cls");
    printf("This is tic-tac-toe game\nChoose your opponent\n\n1.Computer\n2.Friend\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        computer();
    }
    else if(ch==2)
    {
        friend();
    }
}
void start()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=' ';
        }
    }
    board(a);
    printf("\nYou start with 'X' and ur opponent will start with 'O'\n");
}
void friend()
{
    start();
    while(1)
    {
        user(a);
        check(a);
        user2(a);
        check(a);
    }
}
void computer()
{
    start();
    while(1)
    {
        comp(a);
        check(a);
        user(a);
        check(a);
    }
}
void result(char n)
{
    if(n=='X') { board(a); printf("You won the game"); exit(0);}
    else if(n=='O') 
    {printf("Opponent won the game"); exit(0); }
}
void user(char a[3][3])
{
    int x,y;
    printf("\nEnter your choice(box index)-");
    scanf("%d%d",&x,&y);
    input(a,x,y,1);
    board(a);
}
void user2(char a[3][3])
{
    int x,y;
    printf("\nEnter your choice(box index)-");
    scanf("%d%d",&x,&y);
    input(a,x,y,2);
    board(a);
}
void comp(char a[3][3])
{
    int i=9;
    pos(a,i);
    board(a);
}
void input(char a[3][3],int x, int y,int n)
{
    if(a[x][y]==' ')
    {
        if(n==1)
        {
            a[x][y]='X';
        }
        else
        {
            a[x][y]='O';
        }
        fflush(stdin);
    }
    else
    {
        if(n==1)
        {
            printf("Enter index of availabe space");
            user(a);
        }
        else if(n==2)
        {
            printf("Enter index of availabe space");
            user2(a);
        }
    }
}
void check(char a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        if( (a[i][0]==a[i][1]) && (a[i][1]==a[i][2]))
        {
            result(a[i][0]);
        }
        else if( (a[0][i]==a[1][i]) && (a[1][i]==a[2][i]) )
        {
            result(a[0][i]);
        }
    }
    if( (a[0][0]==a[1][1]) && (a[1][1]==a[2][2]) )
    {
        result(a[0][0]);
    }
    else if( (a[0][2]==a[1][1]) && (a[1][1]==a[2][0]) )
    {
        result(a[1][1]);
    }
    int s=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]!=' ')
            {
                s++;
            }
        }
    }
    if(s==9)
    {
        printf("\nGame Draw\n");
        exit(0);
    }
}
void pos(char a[3][3], int g)
{
    int i,j;
    int n[8]={0,0,0,0,0,0,0,0};
    int t[8]={0,0,0,0,0,0,0,0};
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='O' || a[i][j]==' ')
            {
                n[i]++;
                if(a[i][j]=='O')
                {
                    t[i]++;
                }
            }
            if(a[j][i]=='O' || a[j][i]==' ')
            {
                n[i+3]++;
                if(a[j][i]=='O')
                {
                    t[i+3]++;
                }
            }
        }
    }
    if(a[0][0]=='O' || a[0][0]==' ') {n[6]++;if(a[0][0]=='O'){t[6]++;}}
    if(a[1][1]=='O' || a[1][1]==' ') {n[6]++;if(a[1][1]=='O'){t[6]++;}}
    if(a[2][2]=='O' || a[2][2]==' ') {n[6]++;if(a[2][2]=='O'){t[6]++;}}
    if(a[0][2]=='O' || a[0][2]==' ') {n[7]++;if(a[0][2]=='O'){t[7]++;}}
    if(a[1][1]=='O' || a[1][1]==' ') {n[7]++;if(a[1][1]=='O'){t[7]++;}}
    if(a[2][0]=='O' || a[2][0]==' ') {n[7]++;if(a[2][0]=='O'){t[7]++;}}
    int temp=0; int s=-1; int p=0;
        for(i=0;i<8;i++)
        {
            if(s<n[i])
            {
                s=n[i];
                temp=i;
            }
            else if(s==n[i])
            {
                s=s+t[temp]; p=n[i]+t[i];
                {
                    if(s<p)
                    {
                        s=n[i];
                        temp=i;
                    }
                    else
                    {
                        s=s-t[temp];
                    }
                }
            }
        }
        temp++;
        int e;
        e=n[temp-1] - t[temp-1];
        if( (a[1][1]!='X')&&(a[2][2])!='X')
        {
            data(a,7,t[6],n[6]);
        }
        else
        {
        if(e==0)
        {
            for(i=0;i<8;i++)
            {
                if( n[i]-t[i] !=0)
                {
                    temp=i+1;
                    data(a,temp,t[temp-1],n[temp-1]);
                }
            }
        }
        else
        {
            data(a,temp,t[temp-1],n[temp-1]);
        }
        }
}
void data(char a[3][3] ,int n,int m,int o)
{
    int r[8]={0,0,0,0,0,0,0,0};
    int z[8]={0,0,0,0,0,0,0,0};
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='X')
            {
                r[i]++;
            }
            if(a[i][j]==' ')
            {
                z[i]++;
            }
            if(a[j][i]=='X')
            {
                r[i+3]++;
            }
            if(a[j][i]==' ')
            {
                z[i+3]++;
            }
        }
    }
    if(a[0][0]=='X') {r[6]++;} if(a[0][0]==' '){z[6]++;}
    if(a[1][1]=='X') {r[6]++;} if(a[1][1]==' '){z[6]++;}
    if(a[2][2]=='X') {r[6]++;} if(a[2][2]==' '){z[6]++;}
    if(a[0][2]=='X') {r[7]++;} if(a[0][2]==' '){z[7]++;}
    if(a[1][1]=='X') {r[7]++;} if(a[1][1]==' '){z[7]++;}
    if(a[2][0]=='X') {r[7]++;} if(a[2][0]==' '){z[7]++;}
    int temp=0;
    for(i=0;i<8;i++)
    {
        if(r[i]==2 && z[i]==1 && (m!=2 || o!=3) )
        {
            temp=i; temp++;
            compinput(a,temp);
            break;
        }
    }
    if(temp==0)
    {
        compinput(a,n);
    }
}
void compinput(char a[3][3],int n)
{
    int i;
    switch(n)
    {
    case 1:
        for(i=2;i>=0;i--)
        {
            if(a[0][i]==' ')
            {
                a[0][i]='O';
                break;
            }
        }
    break;
    
    case 2:
        for(i=2;i>=0;i--)
        {
            if(a[1][i]==' ')
            {
                a[1][i]='O';
                break;
            }
        }
    break;
    case 3:
        for(i=2;i>=0;i--)
        {
            if(a[2][i]==' ')
            {
                a[2][i]='O';
                break;
            }
        }
    break;
    case 4:
        for(i=2;i>=0;i--)
        {
            if(a[i][0]==' ')
            {
                a[i][0]='O';
                break;
            }
        }
    break;
    case 5:
        for(i=2;i>=0;i--)
        {
            if(a[i][1]==' ')
            {
                a[i][1]='O';
                break;
            }
        }
    break;
    case 6:
        for(i=2;i>=0;i--)
        {
            if(a[i][2]==' ')
            {
                a[i][2]='O';
                break;
            }
        }
    break;
    case 7:
        for(i=0;i<3;i++)
        {
            if(a[i][i]==' ')
            {
                a[i][i]='O';
                break;
            }
        }
    break;
    case 8:
        if(a[0][2]==' ') { a[0][2]='O';}
        else if(a[2][0]==' ') {a[2][0]='O';}
        else if(a[1][1]==' ') {a[1][1]='O';}
    break;
    }
}

void main()
{
    screen();
}