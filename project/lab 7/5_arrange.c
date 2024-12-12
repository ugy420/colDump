/*
#include <stdio.h>
#include <string.h>

void main()
{
    char str[100],ch;
    int i,j,lim;

    printf("Enter the string:\n");
    fgets(str,sizeof str,stdin);

    lim = strlen(str);
    for(i=1;i<lim;i++)
    {
        for(j=0;j<lim-i;j++)
        {
            if(str[j]>str[j+1])
            {
                ch = str[j];
                str[j] = str[j+1];
                str[j+1] = ch;
            }
        }
    }
    printf("After sorting the string:\n%s", str);
}
*/
