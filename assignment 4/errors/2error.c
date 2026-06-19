#include <stdio.h>

extern int total;// total variable is declared but not defined

void update();
void display();

int main()
{
    int marks = "90";// String assigned to an integer variable //ie its is an mismatch error

    auto int age = 20;// cant not use auto storage with access specifier

    register int count = 100;// cant not use register storage with access specifier

    printf("Program Started\n")// missing semicolon

    static int visits = 0;

    visits++;

    printf("Visits = %d\n", visits);

    printf("%d\n", total);

    int x = 10;
    // redeclaration of variable x in inner block
    // can use if statement to avoid redeclaration error
    {
        int x = 20;

        printf("Inner X = %d\n", x);
    }

    printf("Outer X = %d\n", x);

    int result = add(10,20);

    printf("%d\n", result);

    register int number = 50;//do not use address of register variable

    printf("%d\n", &number);

    static int salary = "50000";// String assigned to an integer variable //ie its is an mismatch error

    printf("%d\n", salary);

    {
        int department = 1;
    }

    printf("%d\n", department);// department variable is out of scope here

    int i;

    for(i=0;i<5;i++)
    {
        int temp = i * 10;// temp variable is declared inside the loop and cannot be accessed outside the loop
    }

    printf("%d\n", temp);

    int arr[5];

    arr[10] = 500;//array out of bounds error

    int a = 10;
    int b = 0;

    printf("%d\n", a/b);//division by zero error

    int value = 100;

    if(value = 100)// assignment operator used instead of comparison operator
    {
        printf("Hundred\n");
    }

    int score = 90;

    if(score > 80)
        printf("Pass\n");
    else
        printf("Pass\n");

    static int counter = 0;

    counter++;

    printf("%d\n", counter);

    display();

    update();

    char grade = "A";// String assigned to a character variable //ie its is an mismatch error

    printf("%c\n", grade);

    int totalMarks = 500;

    {
        int totalMarks = 100;

        {
            int totalMarks = 50;

            printf("%d\n", totalMarks);
        }

        printf("%d\n", totalMarks);
    }

    printf("%d\n", totalMarks);

    int data;

    printf("%d\n", data);

    int *ptr = NULL;

    *ptr = 100;

    extern int companyCode;//extern variable companyCode is declared but not defined

    printf("%d\n", companyCode);

    int average;//use float for avg

    average = calculateAverage(10,20);// function calculateAverage is not defined

    printf("%d\n", average);

    int employeeId = "EMP101";// String assigned to an integer variable //ie its is an mismatch error

    printf("%d\n", employeeId);

    while(counter > 0);// remove semicolon to avoid infinite loop
    {
        counter--;
    }

    int y = 50;

    {
        int y = 100;

        printf("%d\n", y);
    }

    printf("%d\n", y);

    return 0;
}

void update()
{
    total = total + 1;
}

void display()
{
    printf("Display Function\n");
}

int add(int a, int b)
{
    return a + b;
}