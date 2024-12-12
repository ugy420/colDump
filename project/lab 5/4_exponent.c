/*
#include <stdio.h>

int pow(int b,int e);

int main()
{
    int b,e;
    printf("Enter base and exponent\n");
    scanf("%d %d", &b,&e);

    printf("%d^%d=", b,e);
    printf("%d", pow(b,e));
}
int pow(int b, int e)
{
    if(e==0)
        return 1;
    else
        return b*pow(b,--e);
}
*/

/*
#include <stdio.h>

void func(void);

void main()
{
    func();
}

void func(void)
{
    int b,e,i,v=1;

    printf("enter base and exponent\n");
    scanf("%d%d", &b,&e);

    for(i=0;i<e;i++)
    {
        v = v*b;
    }
    printf("%d^%d=%d", b,e,v);
}
*/
