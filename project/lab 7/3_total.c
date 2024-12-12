/*
#include <stdio.h>
#include <string.h>

void main()
{
    int i,w=0;
    char str[100];

    printf("Enter the string:\n");
    fgets(str,sizeof str,stdin);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] == ' ' && str[i+1] != ' ')
        {
            w++;
        }
    }
    printf("Numbers of words in the given string are: %d\n", w+1);
}
*/
