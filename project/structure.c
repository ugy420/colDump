/*
// Introduction to structure
#include <stdio.h>
#include <string.h>

int main()
{
    struct student_t_distribution
    {
        char name[30];
        int roll_no;
    }stud1, stud2, *ptr1, *ptr2;
    ptr1=&stud1; ptr2=&stud2;
    // getting values for the first student

    printf("\n\n\t\tDetails of two students: ");
    strcpy(ptr1->name, "Karma D. Dema");

    ptr1->roll_no=10;

    // getting inputs for the second student
    printf("\nEnter the details of second student: ");

    printf("\nEnter the name: ");
    fgets((*ptr2).name, 30, stdin);
    printf("\nEnter the Roll number: ");
    scanf("%d", &ptr2->roll_no);

    // Displaying for the first student
    printf("\n\n\t\tDetails of the first students: ");
    printf("\n-----------------------------------------------");
    printf("\nName=%s", ptr1->name);
    printf("\nRoll number = %d", ptr1->roll_no);

    //Displaying for the second student
    printf("\n\n\t\tDetails of the second students: ");
    printf("\n-----------------------------------------------");
    printf("\nName=%s", ptr2->name);
    printf("Roll number = %d", ptr2->roll_no);
}




// passing structure to a function
#include <stdio.h>
struct student
{
    char name[50];
    int age;
};
//function prototype
void display(struct student s);

int main()
{
    struct student s1;
    printf("Enter name: ");
    // read string input from the user until \n is entered \n is discarded
    scanf("%[^\n]%*c", s1.name);
    printf("Enter age: ");
    scanf("%d", &s1.age);
    display(s1);
    return 0;
}
void display(struct student s)
{
    printf("\nDisplaying information\n");
    printf("Name: %s", s.name);
    printf("\nAge: %d\n", s.age);
}


// return structure from a function
#include <stdio.h>
struct student
{
    char name[50];
    int age;
};

// function prototype (declaration)
struct student getInformation(void);

int main()
{
    struct student s;
    s = getInformation();
    printf("\nDisplaying information\n");
    printf("Name: %s", s.name);
    printf("\nRoll: %d\n", s.age);
    return 0;
}

struct student getInformation(void)
{
    struct student s1;
    printf("Enter name: ");
    fgets(s1.name, 100, stdin);
    //scanf("%[^\n]%*c", s1.name);
    printf("Enter age: ");
    scanf("%d", &s1.age);
    return s1;
};


//passing structure by reference
#include <stdio.h>
typedef struct Complex//typedef used here to create an alias of new structure data type
{
    float real;
    float imag;
}complex;

void addNumbers(complex c1,complex c2, complex *result);//function declaration

int main()
{
    complex c1,c2,result;//declaring structure variables
    //struct Complex c1,c2;
    printf("For first number enter real number:\n");
    scanf("%f", &c1.real);
    printf("For first number enter imaginary number:\n");
    scanf("%f", &c1.imag);
    printf("For second number enter real number:\n");
    scanf("%f", &c2.real);
    printf("For second number enter imaginary number:\n");
    scanf("%f", &c2.imag);

    addNumbers(c1,c2,&result);//calling function, passing function variables and address of a result variable which is a structure type.
    printf("\nresult.real = %.3f\n", result.real);//prints three values after decimal
    printf("result.img = %.1f", result.imag);//prints one value after decimal
    return 0;
}
void addNumbers(complex c1,complex c2, complex *result)//called function
{
    //can use either of these styles
    (*result).real = c1.real+c2.real;
    result->imag = c1.imag+c2.imag;
}


//intro to union
#include <stdio.h>
union unionJob
{
    int age[32];//4*32
    float salary;
    int workerNo;
}uJob;
struct structJob
{
    int age[32];//4*32
    float salary;
    int workerNo;
}sJob;

int main()
{
    printf("size of union = %lu bytes\n", sizeof(uJob));
    printf("size of structure = %lu bytes\n", sizeof(sJob));
    return 0;
}


//assigning unions
#include <stdio.h>

union Job
{
    float salary;
    float workerNo;
}j;

int main()
{S
    j.salary = 12.3;
    printf("Salary = %.1f\n", j.salary);
    //when j.workerNo is assigned a value,
    //j.salary will no longer hold 12.3
    j.workerNo = 10;
    printf("Salary = %.1f\n", j.salary);
    printf("Number of workers = %.1f\n", j.workerNo);
    return 0;
}
*/

//

