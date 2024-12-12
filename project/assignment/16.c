/*
#include <stdio.h>

void fiboS(int *a, int *b, int *c, int *N);

int main()
{
    int x=0,y=1,z,N;

    printf("\nEnter the limit: ");
    scanf("%d", &N);


    fiboS(&x,&y,&z,&N);

    printf("\n");
}

void fiboS(int *a, int *b, int *c, int *N)
{

    if(c>N)
    {
        return 0;
    }
    else
    {
        *c = *a + *b;
        *a = *b;
        *b = *c;

        if(*c<=*N)
            printf("%d\t", *c);

        fiboS(*a,*b,*c,*N);
    }

}
*/
