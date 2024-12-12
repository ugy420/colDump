/*
#include <stdio.h>
void main()
{
    char word1[40],word2[40],word3[40];

    printf("\nEnter text:\n");
    scanf("%s %s %s",word1,word2,word3);

    printf("\nWord1=%s\nWord2=%s\nWord3=%s",word1,word2,word3);
}
*/
/*
#include <stdio.h>
void main()
{
    char ch;
    printf("Enter a character: ");
    ch=getchar();
    printf("The character entered is %c", ch);
}
*/

/*
//fgets() function
#include <stdio.h>
int main()
{
    char st[100];

    printf("enter your name: ");
    fgets(st, 100, stdin);

    printf("%s is your name", st);
}
*/


/*
//putchar & puts

#include <stdio.h>
void main()
{
    char name[6]="PARIS";
    int i;
    for(i=0;i<6;i++)
    {
        putchar(name[i]);
        putchar('\n');
    }
    puts(name);
}
*/
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char first_string[20];  // declaration of char array variable
    char second_string[20]; // declaration of char array variable
    char third_string[30];  // declaration of char array variable
    // int i; // integer variable declaration

    printf("Enter the first string: ");
    scanf("%s", first_string);
    printf("\nEnter the second string: ");
    scanf("%s", second_string);
    printf("\nLength of string 1: %lu", strlen(first_string));
    printf("\nLength of string 2: %lu", strlen(second_string));
    printf("\nstring copy: %s", strcpy(third_string, second_string));
    printf("\nThe third string is: %s", third_string);
    printf("\nstring comparison: %d", strcmp(first_string, second_string));
    printf("\nyour name is %s \n", strcat(first_string, second_string));
}
*/
