#include <stdio.h>
#include <stdlib.h>

// // int main()
// // {
// //     int a = 10;
// //     int *p;
// //     p = &a;

// //     printf("using pointer %d %d", *p, a);
// // }

// int main()
// {
//     int A[5] = {2, 4, 6, 8, 10};
//     int *p;
//     p = A;

//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", p[i]);
//     }
// }

int main()
{
    int *p;
    p = (int *)malloc(5 * sizeof(int));

    p[0] = 10;
    p[1] = 15;
    p[2] = 14;
    p[3] = 21;
    p[4] = 31;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
    // deallocating the memory
}

// size of the pointer is independent of the data type that it points to.