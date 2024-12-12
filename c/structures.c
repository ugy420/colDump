#include <stdio.h>

struct Rectangle
{
    int length; // 4
    int width;  // 4
    char x;     // should be 1
};

/*
struct Rectangle{
    int length;
    int width;
} r1,r2;
    is another way to declare
*/

int main()
{
    struct Rectangle r1 = {10, 5};

    printf("%d\n", sizeof(r1));

    printf("%d", r1.length);

    return 0;
}