/*#include <stdio.h>
int main()
{
    int val,n1=500,n2=750,n3=150;
    val = (((n1<n2)&&(n1<n3))?n1:((n2<n3)?n2:n3));
    val+=100;
    printf("\nThe value displayed is %d", val);
    return 0;
}
*/
/*
#include <stdio.h>
void main()
{
    int num1=50,num2=55;
    while(num1>25 && num2>35)
    {
        printf("%d", (50*num2/num1));
        num1-=1;
        num2-=2;
    }
}
*/
/*
#include <stdio.h>
int main()
{
    char str1[]={'H','e','l','l','o','\0'};
    char str2[]={'H','e','l','l','o'};
    printf("%d", strcmp(str1,str2));
}
*/
/*
#include <stdio.h>
#define X 1677
int main()
{
    if(X%2==1)
    {
        printf("odd");
    }
}
*/
/*
#include <stdio.h>
int myfun(int x);
int main()
{
    int x=5,res;
    res=myfun(x);
    printf("\n%d", res);
    return 0;
}
int myfun(int x)
{
    if(x==0)
    {
        return 1;
    }
    return(x*myfun(x-1));

}
*/
/*
#include <stdio.h>
int main()
{
    int num1=32,num2=0,i=0,rem;
    int num=num1;
    while(num1!=0)
    {
        rem = num1%2;
        num2=num2+rem*pow(10,i);
        num1=num1/2;
        i++;
    }
    printf("%d", num2);
}
*/
/*
#include <stdio.h>
int main()
{
    char str[]="Royal University of Bhutan";
    printf("//%-12.9s//", str);
}
*/
/*
#include <stdio.h>
#include <string.h>
void main()
{
    int num1,num2,res=0;
    float result;
    char ch;
    printf("Enter two numbers: ");
    scanf("%d %d" ,&num1,&num2);
    printf("Choose operation");
    scanf(" %c", &ch);
    switch('ch')
    {
    case '+':
        result=num1+num2;
        break;
    case '-':
        result=num1-num2;
        break;
    }
    printf("FR %d %c %d = %f\n", num1,ch,num2,result);
}
*/
/*
#include <stdio.h>

int main()
{
    int num=199;
    while(num<=210)
    {
        if(num==208)
        {
            printf("\n%d\t", num+3);
        }
        num+=3;
    }
}
*/

#include <stdio.h>


