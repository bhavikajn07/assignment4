#include <stdio.h>

int totalStudents = 500;

void updateCount();
void displayData(int value);

int main()
{
    int department = 1 // ; missing semicolon
    // syntax error
    int marks = "90";//can not assign string to int
    // mismatch error
    printf("Program Started\n");

    int x = 10;
    // missing if statement
    {
        int x = 20;

        printf("Inner x = %d\n", x);
    }

    printf("Outer x = %d\n", x);

    if(x = 10)
    {
        printf("X is Ten\n");
    }

    printf("%d\n", score); // score is undeclared variable use marks instead of score // ie it is a compile time error

    int totalStudents = 100; // redeclaration error 

    printf("Students = %d\n", totalStudents);
    // missing if statement
    {
        int department = 2;

        printf("Department = %d\n", department);
    }

    printf("Department = %d\n", department);

    int a = 10;
    int b = 20;

    int sum;

    sum = add(a,b);// add is an undeclared function // ie it is an linker error

    printf("Sum = %d\n", sum);

    {
        int temp = 50;
    }

    printf("%d\n", temp);// temp is out of scope // ie it is a compile time error

    int arr[5];

    arr[10] = 100;// array out of bounds error // ie it is a runtime error

    float salary = 50000.50;

    printf("%d\n", salary);// salary is a float variable and %d is a format specifier for int // ie it is a compile time error

    int count = 10;

    {
        count = count + 5;

        int count = 100;

        printf("%d\n", count);
    }

    printf("%d\n", count);

    int i;

    for(i=0;i<5;i++)
    {
        int result = i * 10;
    }

    printf("%d\n", result);// result is out of scope // ie it is a compile time error

    int age = 18;

    if(age > 18)
        printf("Eligible\n");
    else
        printf("Eligible\n");

    int value = 50;

    displayData();// no argument passed to function // ie it is a compile time error

    updateCount();

    printf("%d\n", totalStudents);

    {
        int totalStudents = 200;

        printf("%d\n", totalStudents);
    }

    printf("%d\n", totalStudents);

    int y = 100;

    {
        int y = 200;

        {
            int y = 300;
            printf("%d\n", y);
        }

        printf("%d\n", y);
    }

    printf("%d\n", y);

    int z = 10;

    while(z > 0);//remove semicolon to avoid infinite loop
    {
        z--;
    }

    char grade = "A";// grade is a character variable and "A" is a string literal // ie it is a compile time error

    int number = 50;

    printf("%s\n", number);// number is an integer variable and %s is a format specifier for string // ie it is a compile time error

    int *ptr = NULL;

    *ptr = 100; // dereferencing a NULL pointer // ie it is a runtime error

    int average;// use float for avg

    average = calculateAverage(10,20);// calculateAverage is an undeclared function // ie it is a linker error

    printf("%d\n", average);

    return 0;
}

void updateCount()
{
    totalStudents = totalStudents + 10;
}

void displayData(int value)
{
    printf("Value = %d\n", value);
}