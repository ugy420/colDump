/*
#include <stdio.h>

int main()
{
    int var=10,*p;
    p=&var;
    // value at the address
    printf("The value of the var is: %d", var);
    printf("\nThe value of the variable var is: %d\n", *p);

    // address of
    printf("\nThe address of variable var is: %p", &var);
    printf("\nThe address of variable var is: %p\n", p);

    printf("\nThe address of pointer p is: %p", &p);
}



#include <stdio.h>

int main()
{
    // different pointers pointing to the same data variable
    char ch='q',*p=&ch,*q=&ch,*r=&ch,*s=&ch;

    printf("%c", ch);
    printf("\n%c %c", *p,*q);
    printf("\n%p", &ch);
    printf("\n%p", r);
    printf("\n%p", s);
    printf("\n%p", &s);
    printf("\n%p", &r);
}



#include <stdio.h>

void main()
{
    int x[5]={1,2,3,4,5},*p,i;
    printf("\nArray Element     Array Value     Address of Array Element    Address of pointer");
    printf("\n*************     ***********     ************************    ******************");
    for(i=0;i<5;i++)
    {
        p=&x[i];
        printf("\nx[%d]\t\t\t%d\t\t%u\t\t\t%u", i,*p,p,&p);
    }
}


#include <stdio.h>
void main()
{
    int x[5]={1,2,3,4,5},*p;
    p=&x[0];

//    The relationship between pointer p and array x can be shown as:
//    p=&x[0]=1000
//    p+1=&x[1]=1002
//    p+2=&x[2]=1004
//    p+3=&x[3]=1006
//    p+4=&x[4]=1008

    printf("\n%d %u", *(p),p);
    printf("\n%d %u", *(p+1),(p+1));
    printf("\n%d %u", *(p+2),(p+2));
    printf("\n%d %u", *(p+3),(p+3));
    printf("\n%d %u", *(p+4),(p+4));
}



#include <stdio.h>
void changeMe(int *y);
void main()
{
    int x=5;
    changeMe(&x);   // Function call by reference
    printf("\nThe value of x is: %d", x); // the value of x(actual  arguments) will be changed since formal argument has changed
}

void changeMe(int *y)
{
    *y=10; // modification in the formal arguments
    printf("\nThe value of x in the called function is: %d", *y);
}



// swap elements using call by reference

#include <stdio.h>
void swap(int *x,int *y);
int main()
{
    int a=5, b=10;
    printf("Before swapping the value of a is %d and b is %d\n\n", a,b);
    swap(&a,&b);
}
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
    printf("After swapping the value of a is %d and b is %d\n\n", *x,*y);
}


// Store n elements in an array and print the elements using pointer.

#include <stdio.h>
int main()
{
    int i,n,*p;
    printf("Enter the number of elements you need: ");
    scanf("%d", &n);
    int arr[n];
    p=&arr[n];

    printf("Now enter the %d elements: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", (p+i));
    }
    printf("The elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n");
}
*/
