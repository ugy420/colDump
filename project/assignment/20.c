/*
#include <stdio.h>

void passMatrice(int a[5][5], int b[5][5]);

int main()
{
    int m1[5][5],m2[5][5],i,j;

    printf("\n\t\tDifference between two 5x5 matrices\n");
    printf("--------------------------------------------------------------------\n");

    printf("\nEnter the elements for 5x5 matrice: \n\n");
    for(i=0;i<5;i=i+1)
    {
        printf("Row %d: ", i+1);

        for(j=0;j<5;j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }
    printf("\nEnter the elements for another 5x5 matrice: \n\n");
    for(i=0;i<5;i++)
    {
        printf("Row %d: ", i+1);

        for(j=0;j<5;j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    passMatrice(m1,m2);
}

void passMatrice(int a[5][5], int b[5][5])
{
    int md[5][5],i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            md[i][j] = a[i][j]-b[i][j];
        }
    }

    printf("\nThe difference between the two matrices:\n\n");
    for(i=0;i<5;i++)
    {
        printf("Row %d: ", i+1);
        for(j=0;j<5;j++)
        {
            printf("%d ", md[i][j]);
        }
        printf("\n");
    }

}
*/
