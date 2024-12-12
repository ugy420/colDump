/*
#include <stdio.h>

void main()
{
    int mat[4][3],i,j;
    printf("enter the values:\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n\n\t\t\titem1\titem2\titem3\n");
    for(i=0;i<4;i++)
    {
        printf("\n\tSales Girl %d:", (i+1));
        for(j=0;j<3;j++)
        {
            printf("\t%d", mat[i][j]);
        }
        printf("\n");
    }
}
*/

/*
#include <stdio.h>
void arrayToFunc(int num);
void main()
{
    int arr[2][2],i,j;
    for(i=1;i<=2;i++)
    {
        for(j=1;j<=2;j++)
            scanf("%d", &arr[i][j]);
    }
    arrayToFunc(arr[1][2]);
}
void arrayToFunc(int x)
{
    printf("\n%d", x);
}
*/
/*
#include<stdio.h>
void arrayToFunct(int x[2]);
void main()
{
    int arr[2][2],i,j;
    for(i=1;i<=2;i++)
    {
        for(j=1;j<=2;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    arrayToFunct(arr[1]);
}
void arrayToFunct(int x[2])
{
    int i;
    for(i=1;i<=2;i++)
    {
        printf("\n%d", x[i]);
    }
}
*/

/*
#include <stdio.h>

void arrayToFunc(int x[1]);
int main()
{
    int arr[5][5],i,j=1;
    printf("enter 2rows and 2columns of elements in an array: ");

    for(i=1;i<=2;i++)
    {
        for(j=1;j<=2;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    arrayToFunc(arr[2]); //if it is arr[1] -> you are passing first row.
}
void arrayToFunc(int x[1])
{
    int j;
    printf("enter 1D elements in a 2D array are ");
    for(j=1;j<=2;j++)
    {
        printf(" %d", x[j]);
    }
    printf("\n");
}
*/

/*
#include <stdio.h>
void arrayToFunc(int x[2][2]);
void main()
{
    int arr[2][2],i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    arrayToFunc((arr));
}
void arrayToFunc(int x[2][2])
{
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}
*/
