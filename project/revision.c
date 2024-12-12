/*
#include <stdio.h>
#include <string.h>

struct std_info
{
    int student_no;
    char name[500];
    int age;
    float height;
    char department[500];
}students[100];

int main()
{
    int i,n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {

        printf("Enter the name: ");
        scanf("%s", students[i].name);
        printf("Enter the age: ");
        scanf("%d", &students[i].age);
        printf("Enter the height: ");
        scanf("%.2f", &students[i].height);
        printf("Enter the name of the department: ");
        fgets(students[i].department, sizeof(students[i].department), stdin);
        fgets(students[i].department, sizeof(students[i].department), stdin);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {

        printf("\nThe student's name is %s", students[i].name);
        printf("\nThe age is %d", students[i].age);
        printf("\nThe height is %f", students[i].height);
        printf("\nThe department is %s", students[i].department);
        printf("\n");
    }
}



*/
