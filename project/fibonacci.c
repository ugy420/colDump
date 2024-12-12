/*
#include <stdio.h>
void fib(int *a, int *b,int *N);

int main()
{
    int a,b,c,i,n=34;


    a = 0;
    b = 1;

    fib(&a,&b,&n);
}

void fib(int *a, int *b,int *N)
{
    int i,c;
    for(i=0;i<*N;i++)
    {
        c = *a+*b;

        *a = *b;

        *b = c;

        if(c<=*N)
            printf("%d\t", c);
    }
}

*/
