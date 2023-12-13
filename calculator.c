#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
double calc(char x, double a, int b)
{
    if(x=='+')  return a+b;
    else if(x=='-') return a-b;
    else if(x=='*') return a*b;
    else if(x=='/') return a/b;
    else if(x=='^') return pow(a,b);
    else printf("Operator not exist. Try new operator and then type %lf again\n",b); return a;
}
double output(double result, char o)
{
    double a,b;
    char x,y;
    scanf("%lf",&a);
    result=calc(o,result,a);
    scanf("%s",&x);
    if(x=='=') return result;
    else {
        scanf("%lf",&b); 
        result= calc(x,result,b);
        scanf("%s",&y);
        if(y=='=')
        {
            return result;
        }
        else
        {
            return output(result,y);
        }
        }
    
}
int main()
{
    system("cls");
    double result=0; char s[3];
    printf("This is arthmetic calculator with x^y operation-");
    printf("\nON\tOFF");
    printf("\nType-");
    scanf("%s",&s);
    char p[3];
    strlwr(s);
    while( strcmp(s,"on")==0)
    {
        system("cls");
        result=output(result, '+');
        printf("%lf",result);
        printf("\nType(ON/OFF)-");
        scanf("%s",&s);
        strlwr(s);
    }
}