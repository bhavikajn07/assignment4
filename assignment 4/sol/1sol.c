#include <stdio.h>

int totalStudents = 500;

void updateCount();
void displayData(int value);
int add(int a, int b);
float calculateAverage(int a, int b);

int main()
{
    int department = 1;

    int marks = 90;

    printf("Program Started\n");

    int x = 10;
    if (x== 20)
    {
        int x = 20;

        printf("Inner x = %d\n", x);
    }

    printf("Outer x = %d\n", x);

    if(x == 10)
    {
        printf("X is Ten\n");
    }

    printf("%d\n", marks);

    totalStudents = 100;

    printf("Students = %d\n", totalStudents);

    {
        int department = 2;

        printf("Department = %d\n", department);
    }

    printf("Department = %d\n", department);

    int a = 10;
    int b = 20;

    int sum;

    sum = add(a,b);

    printf("Sum = %d\n", sum);

    {
        int temp = 50;

        printf("%d\n", temp);
    }

    int arr[5];

    arr[4] = 100;

    float salary = 50000.50;

    printf("%f\n", salary);

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
    
        printf("%d\n", result);
    }

    int age = 18;

    if(age > 18)
        printf("Eligible\n");
    else
        printf("Ineligible\n");

    int value = 50;

    displayData(value);

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

    while(z > 0)
    {
        z--;
    }

    char grade = 'A';

    int number = 50;

    printf("%d\n", number);

    int *ptr = NULL;

    float average;

    average = calculateAverage(10,20);

    printf("%f\n", average);

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

int add(int a, int b)
{
    return a + b;
}

float calculateAverage(int a, int b)
{
    return (a + b) / 2.0;
}