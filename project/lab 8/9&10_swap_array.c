/*
#include <stdio.h>

main()
{
    int *p,i,j,n,tp;
    printf("enter the numbers of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d number of elements in the array:\n", n);
    for(i=0;i<n;i++)
    {
        printf("element %d: ", i);
        scanf("%d", p+i);
    }

    printf("The elements in the array after sorting:\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(p+i)>*(p+j))
            {
                tp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = tp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("element %d: %d\n", i,*(p+i));
    }
}
*/
