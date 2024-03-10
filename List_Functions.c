#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
int **list,i=-1,*size;
char **name;
void menu();
void create();
void edit();
void merge();
void search();
void data();
void insert(int a);
void delete(int a);
void sort(int a);
void math(int a);
void vanish(int a);
void add(int a);
void sub(int a);
void mul(int a);
void divide(int a);

void data()
{
    printf("Choose from below list-\n");
        for(int j=0;j<=i;j++)
        {
            printf("%d. %s\n",j+1,name[j]);
        }
}
void insert(int a)
{
    int pos,val;
    printf("Enter position(1-%d) to add element-",size[a]); scanf("%d",&pos);
    printf("Enter value to add-"); scanf("%d",&val);
    if(pos<0||pos>size[a])
    {
        printf("Invalid position\n");
        insert(a);
    }
    else
    {
        size[a]++;
        list[a]=(int*)realloc(list[a],size[a]*sizeof(int));
        for(int i=size[a];i>pos-1;i--)
        {
            list[a][i]=list[a][i-1];
        }
        list[a][pos-1]=val;
        printf("Element added!\n");
    }
    menu();
}
void delete(int a)
{
    int pos;
    printf("Enter posiion(1-%d) of element to delete-",size[a]); scanf("%d",&pos);
    if(pos<0||pos>size[a])
    {
        printf("Invalid position\n");
        delete(a);
    }
    else
    {
        size[a]--;
        for(int i=pos-1;i<size[a];i++)
        {
            list[a][i]=list[a][i+1];
        }
        list[a]=(int*)realloc(list[a],size[a]*sizeof(int));
        printf("Element deleted!\n");
    }
    if(size[a]==0)
    {
        printf("List is now empty, request to delete the entire list and create a new one.");
        vanish(a);
    }
    menu();
}
void sort(int a)
{
    int i, j, minIndex;
    for (i = 0; i < size[a]-1; i++) //selection sort
    {
        minIndex = i;
        for (j = i+1; j < size[a]; j++) 
        {
            if (list[a][j] < list[a][minIndex]) {
                minIndex = j;
            }
        }
        int temp = list[a][i];
        list[a][i] = list[a][minIndex];
        list[a][minIndex] = temp;
    }
    printf("%s sorted list is-\t",name[a]);
        for(int j=0;j<size[a];j++)
        {
            printf("%d\t",list[a][j]);
        } printf("\n");
}
void math(int a)
{
    fflush(stdin);
    printf("Choose what operation you want to perform-\n");
    printf("1.Add\n2.Subtract\n3.Multiply\n4.Division\n");
    switch(getchar())
    {
        case '1': add(a); break;
        case '2': sub(a); break;
        case '3': mul(a); break;
        case '4': divide(a); break;
        default: printf("Invalid choice, try again"); math(a);
    }
    menu();
}
void add(int a)
{
    fflush(stdin);
    printf("Choose-\n1.Add value to %s list\n2.Add %s list to  another list\n",name[a],name[a]);
    switch(getchar())
    {
        case '1':
        int val;
        printf("Enter value to add-");
        scanf("%d",&val);
        for(int i=0;i<size[a];i++)
        {
            list[a][i]+=val;
        }
        break;
        case '2':
        printf("Choose 2nd list to add-");
        data();
        int b; scanf("%d",&b); b--;
        int x=size[a]<size[b]?size[a]:size[b];
        for(int i=0;i<x;i++)
        {
            list[a][i]+=list[b][i];
        }
        break;
    }
    menu();
}
void sub(int a)
{
    fflush(stdin);
    printf("Choose-\n1.Subtract value from %s list\n2.Subtractanother list from %s list\n",name[a],name[a]);
    switch(getchar())
    {
        case '1':
        int val;
        printf("Enter value to subtract-");
        scanf("%d",&val);
        for(int i=0;i<size[a];i++)
        {
            list[a][i]-=val;
        }
        break;
        case '2':
        printf("Choose 2nd list to subtract-");
        data();
        int b; scanf("%d",&b); b--;
        int x=size[a]<size[b]?size[a]:size[b];
        for(int i=0;i<x;i++)
        {
            list[a][i]-=list[b][i];
        }
        break;
    }
    menu();
}
void mul(int a)
{
    fflush(stdin);
    printf("Choose-\n1.Multiply value to %s list\n2.Multiply %s list to  another list\n",name[a],name[a]);
    switch(getchar())
    {
        case '1':
        int val;
        printf("Enter value to multiply-");
        scanf("%d",&val);
        for(int i=0;i<size[a];i++)
        {
            list[a][i]*=val;
        }
        break;
        case '2':
        printf("Choose 2nd list to multiply");
        data();
        int b; scanf("%d",&b); b--;
        int x=size[a]<size[b]?size[a]:size[b];
        for(int i=0;i<x;i++)
        {
            list[a][i]*=list[b][i];
        }
        break;
    }
    menu();
}
void divide(int a)
{
    fflush(stdin);
    printf("Choose-\n1.Divide value to list\n2.Divide another list from %s list\n",name[a],name[a]);
    switch(getchar())
    {
        case '1':
        int val;
        printf("Enter value to divide-");
        scanf("%d",&val);
        for(int i=0;i<size[a];i++)
        {
            list[a][i]/=val;
        }
        break;
        case '2':
        printf("Choose 2nd list to divide-");
        data();
        int b; scanf("%d",&b); b--;
        int x=size[a]<size[b]?size[a]:size[b];
        for(int i=0;i<x;i++)
        {
            list[a][i]/=list[b][i];
        }
        break;
    }
    menu();
}
void vanish(int a)
{
    fflush(stdin);
    printf("Are you sure want to delete %s list?(y/n)",name[a]);
    switch(getchar())
    {
        case 'y':
        for(int j=a;j<i;j++)
        {
            *(list+j)=*(list+j+1);
            size[j]=size[j+1];
            strcpy(name[j],name[j+1]);
        }
        i--;
        list = (int**)realloc(list,(i+1)*sizeof(int*));
        name = (char**)realloc(name,(i+1)*sizeof(char*));
        size = (int*)realloc(size,(i+1)*sizeof(int));
        printf("List deleted\n");
        break;
        case 'n':
        edit();
        default:
        printf("Choose correct input.\n"); vanish(a);
    }
    edit();
}

void create()
{
    i++;
    if(list==NULL)
    {
        list = (int**)malloc((i+1)*sizeof(int*));
        name = (char**)malloc((i+1)*sizeof(char*));
        size = (int*)malloc((i+1)*sizeof(int));
    }
    else
    {
        list = (int**)realloc(list,(i+1)*sizeof(int*));
        name = (char**)realloc(name,(i+1)*sizeof(char*));
        size = (int*)realloc(size,(i+1)*sizeof(int));
    }
    int n;
    name[i]=(char*)malloc(100*sizeof(char));
    printf("Enter name of list-");
    scanf("%s",name[i]);
    printf("Enter size of list-");
    scanf("%d",&size[i]);
    list[i] = (int*)calloc(n,sizeof(int));
    printf("List created-%s\n",name[0]);
    for(int a=0;a<size[i];a++)
    {
        scanf("%d",&list[i][a]);
    }
    menu();
}
void edit()
{
    if(i==-1)
    {
        printf("No lists, try creating one\n");
        menu();
    }
    fflush(stdin);
    data();
    int a; scanf("%d",&a);
    a--;
    if(a<0||a>i) { printf("No list exists, pick availabe lists!"); edit();}
    printf("%s list elements are-\t",name[a]);
        for(int j=0;j<size[a];j++)
        {
            printf("%d\t",list[a][j]);
        } printf("\n");
    printf("Choose what you want to do with %s-",name[a]);
    printf("\n1.Insert\n2.Delete\n3.Sort\n4.Perform arthematic operations\n5.Delete entire list\n6.Exit\n");
    fflush(stdin);
    switch(getchar())
    {
        case '1': insert(a); break;
        case '2': delete(a); break;
        case '3': sort(a); break;
        case '4': math(a); break;
        case '5': vanish(a); break;
        case '6': menu(); break;
        default: printf("Invalid input, try again"); edit();
    }
}
void merge()
{
    if(i==-1)
    {
        printf("No lists, try creating one\n");
        menu();
    }
    int a,b;
    data();
    scanf("%d",&a);
    printf("Choose 2nd list to add to previous list");
    data();
    scanf("%d",&b);
    a--; b--;
    if(a<0||a>i||b<0||b>i) {printf("No list exists, pick availabe lists!"); merge();}
    int x=size[a];
    size[a]=size[a]+size[b];
    list[a]=(int*)realloc(list[a],size[a]*sizeof(int));
    for(int i=x;i<size[a];i++)
    {
        list[a][i]=list[b][i-x];
    }
    printf("%s list elements are-\n",name[a]);
        for(int j=0;j<size[a];j++)
        {
            printf("%d\t",list[a][j]);
        } printf("\n");
    menu();
}
void search()
{
    if(i==-1)
    {
        printf("No lists, try creating one\n");
    }
    else
    {
        data();
        fflush(stdin);
        int a; scanf("%d",&a);
        a--; int val,pos=-1;
        if(a<0||a>i) {printf("No list exists, pick availabe lists!"); search();}
        printf("Enter value to search-"); scanf("%d",&val);
        for(int i=0;i<size[a];i++) //my own search algo
        {
            if(list[a][i]==val||list[a][size[a]-i]==val)
            {
                pos=list[a][i]==val?i:size[a]-i;
            }
        }
        if(pos>-1) printf("%d found at index %d",val,pos);
        else printf("Not found");
    }
    menu();
}
void display()
{
    if(i==-1)
    {
        printf("No lists, try creating one\n");
    }
    else
    {
        data();
        fflush(stdin);
        int a; scanf("%d",&a);
        a--;
        if(a<0||a>i) {printf("No list exists, pick availabe lists!"); display();}
        printf("%s list elements are-\n",name[a]);
        for(int j=0;j<size[a];j++)
        {
            printf("%d\t",list[a][j]);
        } printf("\n");
    }
    menu();
}
void menu()
{
    printf("\nChoose-\n1.Create\n2.Edit\n3.Merge\n4.Search\n5.Display\n6.Exit\n");
    fflush(stdin);
    switch(getchar())
    {
        case '1': create(); break;
        case '2': edit(); break;
        case '3': merge(); break;
        case '4': search(); break;
        case '5': display(); break;
        case '6': free(list); free(size); free(name); exit(0);
        default: printf("Invalid input, try again"); menu();
    }
}
void main()
{
    printf("This is list interface, create,edit and perform other operations on your lists");
    menu();
}