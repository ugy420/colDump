/*
#include <stdio.h>
int main()
{
    int m,n,i,j;

    printf("Enter the number of ROWs you require: ");
    scanf("%d", &m);
    printf("Enter the number of COLUMNs you require: ");
    scanf("%d", &n);
    int arr[m][n];

    printf("Enter %d x %d matrix elements: ", m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The entered %d x %d matrix elements are\n", m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int small=arr[0][0];
    printf("The smallest element of an array is: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(small > arr[i][j])
            {
                small=arr[i][j];
            }
        }
    }
    printf("%d", small);
}
*/



/*
//To add two matrices;
#include <stdio.h>

int main()
{
    int arr1[20], arr2[20], sum[20], i;

    printf("Enter 5 elements for Array1: ");
    for(i=0;i<5;i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 5 elements for Array2: ");
    for(i=0;i<5;i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("The sum of the two Arrays is: ");
    for(i=0;i<5;i++)
    {
        sum[i] = arr1[i]+arr2[i];
    }

    for(i=0;i<5;i++)
    {
        printf("%d ", sum[i]);
    }
}
*/
