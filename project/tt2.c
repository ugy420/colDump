/*
#include <stdio.h>

int main()
{
    int a,b;
    scanf("%2d %4d", &a, &b);
    printf("%d %d",a,b);
}
*/
/*
#include <stdio.h>
int main()
{
    int x=5,y=25;
    for(;x<y;)
    {
        printf("%d", (x++*x++));
        x+=10;
        y-=10;
    }
}
*/
/*
#include <stdio.h>
void abc(int a)
{
    a=a+5;
}
void main()
{
    int a=10;
    abc(a);
    printf("%d", a);
}
*/

/*
#include <stdio.h>
int a=6;
void main()
{
    int a=5;
    a=7;
    printf("%d", a);
}
*/
/*
#include <stdio.h>
int main()
{
    int x=3,y=5,z=7;
    int a,b;
    a = x * 2 + x / 5- --z * y-- +5;
    b=++x*(y-3)/2-z++*y;
    printf("%d %d",a,b);
}
*/
/*
#include <stdio.h>
float val=3.14;
void Funct(float x)
{
    int x1=50,y=5;
    float total;
    total=x*y*y;
    printf("\nThe total is %f", total);
}
int Funct1(int a,int b)
{
    Funct(val);
    return a*b;
}
int main()
{
    int no1=80,no2=10;
    float n1=10.5,n2=10.5;
    printf("\nThe value is: %d",Funct1(no1,no2));
    Funct(n2);
    return 0;
}
*/
/*
#include <stdio.h>
void main()
{
    int i=5,j;
    while(i>=1)
    {
        j=1;
        while(j<=i)
        {
            printf("%d\t", j+j);
            j++;
        }
        i--;
        printf("\n");
    }
}
*/
/*
#include <stdio.h>

void square(int val);
int main()
{
    int n;
    printf("Enter any number:\n");
    scanf("%d", &n);
    square(n);
}
void square(int val)
{
    printf("%d",val*val);
}
*/
