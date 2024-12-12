/*
#include <stdio.h>

int pow(int b,int e);
int main()
{
    int b,e;
    printf("enter base & exponent");
    scanf("%d%d", &b,&e);

    printf("%d", pow(b,e));
}
int pow(int b,int e)
{
    if(e==0)
    {
        return 1;
    }
    else
    {
        return b*pow(b,--e);
    }
}
*/
