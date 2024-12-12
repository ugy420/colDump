/*
#include <stdio.h>
#include <string.h>


int main()
{
    int i,v=0,c=0,*p,*q,*r;
    char str[100];
    p=&str[100];
    q=&v;
    r=&c;

    printf("enter your string: ");
    fgets(str,sizeof str,stdin);

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            (*q)++;
        }
        else
        {
            (*r)++;
        }
    }
    printf("There are %d vowels and %d consonants", *q,(*r-1));
}
*/
