//delete data function under process
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int l;
FILE* fp;
struct report
{
    char name[10];
    int marks[5] , roll ;
};
typedef struct report report;
/*void choose(report*,char**,int,int);
void data(report*,char**,int,int);
void add(report*,char**,int,int);
void create(report*,char**,int,int);
void display(report*,char**,int,int);*/
void choose(report *r, char sub[5][10], int f , int n);
void data(report* r, char sub[5][10],int f,int n);
void create(report *r, char sub[5][10],int f, int n);
void display(report *r, char sub[5][10] ,int f, int n);
void add(report *r, char sub[5][10], int f, int n);
void fileprint(report *r, char sub[5][10], int n);

void choose(report *r, char sub[5][10], int f , int n)
{
    char info[100]; int j=0;
    system("cls");
    int ch;
    printf("Choose-\n1.Add more\n2.Display\n3.Delete\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        add(r,sub,f,n); break;
        case 2:
        display(r,sub,f,n); break;
        case 3:
        printf("Under way"); break;
        case 4:
        fileprint(r,sub,n);
        break;
        default :
        printf("Wrong Choice\n");
        choose(r,sub,f,n);
    }
}
void data(report *r, char sub[5][10],int f,int n)
{
    int sum; int i;
    for(int h=f;h<n;h++)
    {   
        sum=0;
        printf("Enter name-");
        scanf("%s",&(r+h)->name);
        printf("Enter marks-\n");
        for(i=0;i<3;i++)
        {
            printf("%s-",sub[i+1]);
            scanf("%d",&(r+h)->marks[i]);
            sum=(r+h)->marks[i] + sum;
        }
        (r+h)->marks[3]= sum/3;
    }
    choose(r,sub,f,n);
}
void create(report *r, char sub[5][10],int f, int n)
{
    r=(report*)malloc(n*sizeof(report));
    data(r,sub,f,n);
}
void add(report *r, char sub[5][10], int f, int n)
{
    f=n;
    printf("Enter number of students-");
    scanf("%d",&n);
    n=n+f;
    r= (report*)realloc(r,n*sizeof(report));
    data(r,sub,f,n );
}
void display(report *r, char sub[5][10] ,int f, int n)
{
    system("cls");
    printf("Marks List\n");
    
    for(int l=0;l<5;l++)
    {
    printf("%s\t",sub[l]);
    }
    printf("\n");
    for(int k=0;k<n;k++)
    {
        printf("%s",(r+k)->name);
        {
            for(int o=0;o<4; o++)
            {
                printf("\t%d",(r+k)->marks[o]);
            }
        }
        printf("\n");
    }
    getch();
    system("cls");
    choose(r,sub,f,n);
}
void main()
{  
    FILE *fr;
    fr= fopen("MarkList.csv","r");
    fseek(fr,0,SEEK_END);
    l= ftell(fr);
    fclose(fr);
    int n,f=0; char sub[6][10]={"Name","Physics","Maths","C-lang","Percentage","\0"};
    report *r;
    printf("Enter number of students-");
    scanf("%d",&n);
    create(r,sub,f,n);
    free(r);
}

void fileprint(report *r, char sub[5][10], int n)
{
    fp= fopen("MarkList.csv","a+");
    if(fp==NULL) printf("Again");
    if(l==0)
    {
    for(int i=0;i<5;i++)
        {
            fputs(sub[i],fp);
            fprintf(fp,",");
        }
    }
    char info[100];
        for(int i=0;i<n;i++)
        {
            sprintf(info,"%s,%d,%d,%d,%d", (r+i)->name, (r+i)->marks[0],(r+i)->marks[1],(r+i)->marks[2],(r+i)->marks[3]);
            //printf("%s",info);
            fprintf(fp,"\n");
            fputs(info,fp);
        }
    fclose(fp);
}
