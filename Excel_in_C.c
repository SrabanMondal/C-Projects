//You can create csv files with this code
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

char file[50];
int row=0;
char **data;
void screen();
void choose();
void filetake();
void create();
void fileopen();
void choose2(int x);
void datafile();
void add();
void delete();
void display();
void save();
void input(char *text);
void view();
void exitfile();
void addfile(int n);
int showf();

void screen()
{
    system("cls");
    char ch;
    printf("This is C excel\nCreate any file for management system\n");
    getch();
    choose();
}
void choose()
{
    system("cls");
    int ch;
    printf("Choose-\n1.Create file\n2.Open existing file\n3.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        create(); break;
        case 2:
        fileopen(); break;
        case 3:
        exit(0);
        default:
        printf("Wrong choice"); choose();
    }
}
void filetake()
{
    printf("Enter file name-");
    scanf("%s",file);
    strcat(file,".csv");
}
void create()
{
    system("cls");
    char e[5]={".csv"};
    printf("\nEnter file name-");
    scanf("%s",file);
    strcat(file,e);
    FILE *fp= fopen(file,"w");
    if(fp==NULL)
    {
        printf("\nFail\nTry again"); choose();
    }
    fclose(fp);
    printf("\n%s file created",file);
    screen();
}
void fileopen()
{
    system("cls");
    int x;
    filetake();
    FILE* fp = fopen(file,"a+");
    if(fp==NULL)
    {
        printf("%s failed to open\nTry again\n",file); add();
    }
    printf("%s opened\n",file);
    fseek(fp,0,SEEK_END);
    if(ftell(fp)==0)
    {
        printf("File empty\n");
        data=(char**)malloc(sizeof(char*)); x=1;
    }
    else
    {
        datafile(); x=2;
    }
    fclose(fp);
    choose2(x);
}
void choose2(int x)
{
    int n;
    switch(x)
    {
        case 1:
        printf("What you want to do?\n1.Add\n2.Exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        add(); break;
        case 2:
        exitfile();
        break;
        default:
        printf("Wrong choice\n"); choose2(x);
    }
        break;
        case 2:
    printf("What you want to do?\n1.Add\n2.Delete\n3.Display\n4.Save\n5.Exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        add(); break;
        case 2:
        showf();
        delete(); break;
        case 3:
        display(); break;
        case 4:
        save(); break;
        case 5:
        exitfile();
        break;
        default:
        printf("Wrong choice\n"); choose2(x);
    }
    break;
    }
}
void datafile()
{
    char *text;
    FILE *fp=fopen(file,"r");
    data=(char**)malloc(sizeof(char*));
    while(fgets(text,100,fp))
    {
        data[row]=(char*)malloc(100*sizeof(char));
        strcpy(data[row],text);
        row++;
        data=(char**)realloc(data,(row+1)*sizeof(char*));
    }
    fclose(fp);
}
void add()
{
    system("cls");
    int n;
    printf("Add data-\nHow many columns you want to add-\n");
    scanf("%d",&n);
    addfile(n);
}
void addfile(int n)
{
    char text[500]={""}; char **cell=(char**)malloc(1*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        cell=(char**)realloc(cell,(i+1)*sizeof(char*));
        cell[i]=(char*)malloc(100*sizeof(char));
        fflush(stdin);
        scanf("%[^\n]s",cell[i]);
        strcat(cell[i],",");
        strcat(text,cell[i]);
        fflush(stdin);
    }
    strcat(text,"\n");
    data[row]=(char*)malloc(100*sizeof(char));
    strcpy(data[row],text);
    row++;
    data=(char**)realloc(data,(row+1)*sizeof(char*));
    printf("Do you want to add more?-");
    char ch;
    scanf("%s",&ch);
    free(cell);
    if(ch=='Y'||ch=='y') 
    {addfile(n);}
    else 
    {
    choose2(2);
    }
}
void delete()
{
    int n; int x;
    printf("Enter which line you want to delete-");
    scanf("%d",&n);
    int i;
    for(i=n-1;i<row-1;i++)
    {
        strcpy(data[i],data[i+1]);
    }
    row--;
    printf("Deleted\n");
    if(row==0) x=1;
    else x=2;
    choose2(x);
}
int showf()
{
    system("cls");
    char *text; int k;
    for(k=0;k<row;k++)
    {
        strcpy(text,data[k]);
        input(text);
        printf("%s",text);
    }
    return 0;
}
void display()
{
    system("cls");
    char *text; int k;
    for(k=0;k<row;k++)
    {
        strcpy(text,data[k]);
        input(text);
        printf("%s",text);
    }
    choose2(2);
}
void input(char *text)
{
    int i,l=0;
    l=strlen(text);
    for(i=0;i<l;i++)
    {
        if(text[i]==',')
        {
            text[i]='-';
        }
    }
    text[l]='\0';
    fflush(stdin);
    fflush(stdout);
}
void save()
{
    FILE *fp=fopen(file,"w");
    if(row==0)
    {
        fputc(EOF,fp);
    }
    else
    {
    for(int i=0;i<row;i++)
    {
        fputs(data[i],fp);
    }
    fclose(fp);
    }
    printf("Saved");
    choose2(2);
}
void view()
{
    char exe[]={"cmd/c"};
    strcat(exe,file);
    system(exe);
}
void exitfile()
{
    printf("Warning!! If you have not saved, all changes will be lost\n"); int ch;
    printf("1.Exit\n2.View in excel\n3.Go back\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: exit(0);
        case 2: view(); break;
        case 3: choose2(2); break;
        default: printf("Wrong Choice\n"); exitfile();
    }
}
void main()
{
    screen();
}
