
/*
// 2020 Part 3 Q3
#include <stdio.h>

void main()
{
    int i=0,j=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i>1)
                break;
        }
        printf("Hi\n");
    }
}
*/

/*
// 2018 Part II Q6
#include <stdio.h>

int factorial(int n);

int main()
{
    int n;
    printf("Enter the number you want the factorial of: ");
    scanf("%d", &n);

    printf("The factorial of %d is: %d" ,n,factorial(n));
}

int factorial(int n)
{
    int fac=1;
    if(n==1)
    {
        return fac;
    }
    else
    {
        fac = n*factorial(n-1);
    }
    return fac;
}
*/

/*
//2016 Part II Q10
#include <stdio.h>
int main()
{
    int a,b,c,i;
    a=0, b=1;

    printf("%d\t%d\t", a,b);

    for(i=1;i<=8;i++)
    {
        c = a+b;
        a = b;
        b = c;

        printf("%d\t", c);

    }
}
*/
