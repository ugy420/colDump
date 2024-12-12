/*

// write to a text file

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    FILE *fptr;

    fptr = fopen("F:\\hello.txt", "w");

    if(fptr==NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr,"%d",num);
    fclose(fptr);
    return 0;
}


// read from a text file

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    FILE *fptr;

    if((fptr = fopen("hello.txt", "r"))==NULL)
    {
        printf("Error! opening file");
    }
    //Program exits if the file pointer returns NULL. exit(1);

    fscanf(fptr,"%d",&num);
    printf("Value of n = %d", num);
    fclose(fptr);

    return 0;
}





// Read from a Binary File using fseek()

#include <stdio.h>

struct twoNum{
    int n1,n2;
};

main()
{
    int n;
    struct twoNum num;

    FILE *fptr;
    if((fptr=fopen("hey.bin","rb"))==NULL)
    {
        printf("ERROR!");
        exit(1);
    }
    fseek(fptr, -sizeof(struct twoNum), SEEK_END);
    for(n=1;n<5;++n)
    {
        fread(&num, sizeof(struct twoNum), 1, fptr);
        printf("n1: %d\tn2: %d\n", num.n1, num.n2);
        fseek(fptr, -2*sizeof(struct twoNum), SEEK_CUR);
    }
    fclose(fptr);
    return 0;
}


// another example

#include <stdio.h>
int main () {
	FILE *fp;
	fp = fopen("file.txt","w+");
	fputs("This is tutorialspoint.com", fp);
	// fprintf(fp, "This is tutorialspoint.com");
	fseek( fp, 7, SEEK_SET );
	fputs(" C Programming Language", fp);
	// fprintf(fp, " C Programming Language");
	fclose(fp);
	return(0);
}
*/
