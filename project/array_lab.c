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

    printf("The sum of the two Arrays is: ")
    for(i=0;i<5;i++)
    {
        sum[i] = arr1[i]+arr2[i];
    }

    for(i=0;i<5=i++)
    {
        printf("%d ", sum[i]);
    }
}
