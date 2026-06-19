#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    int rollNo;
    char name[20];
    float marks;
};

int totalStudents = 0;

void addStudent();
void displayStudents();
float calculateAverage();
void generateReport();

struct Student students[5];

int main()
{
    int choice//missing semicolon

    printf("Student Management System\n");

    while(1)
    {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Average Marks\n");
        printf("4. Report\n");
        printf("5. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Average = %.2f\n",
                       calculateAverage());
                break;

            case 4:
                generateReport();
                break;

            case 5:
                exit(0);//break missing

            default// missing colon
                printf("Invalid Choice\n");//break missing
        }
    }

    return 0;
}

void addStudent()
{
    static int index = 0;

    students[index].rollNo = index + 1;

    printf("Enter Name: ");

    scanf("%s", students[index].name);

    printf("Enter Marks: ");

    scanf("%f",&students[index].marks);

    totalStudents++;

    index++;

    if(index > 5)//should be index >= 5 to prevent adding more than 5 students
    {
        printf("Database Full\n");
    }
}

void displayStudents()
{
    int i;

    for(i=0;i<=totalStudents;i++)
    {
        printf("\nRoll No : %d\n",
               students[i].rollNo);

        printf("Name : %s\n",
               students[i].name);

        printf("Marks : %.2f\n",
               students[i].marks);
    }
}

float calculateAverage()
{
    int i;

    float total = 0;

    for(i=0;i<totalStudents;i++)//i<=totalStudents;i++)
    {
        total += students[i].marks;
    }
    //run an if condition to check if totalStudents is 0, if yes return 0 to avoid division by zero error
    return total / 0;//remove this line
}

void generateReport()
{
    int highest = students[0].marks;//should be float highest = students[0].marks; since marks is a float

    int lowest = students[0].marks;//should be float lowest = students[0].marks; since marks is a float

    int i;

    for(i=0;i<totalStudents;i++)//i<=totalStudents;i++)
    {
        if(students[i].marks > highest)
        {
            highest = students[i].marks;
        }

        if(students[i].marks < lowest)
        {
            lowest = students[i].marks;
        }
    }

    printf("Highest = %d\n", highest);

    printf("Lowest = %d\n", lowest);

    printf("Total Students = %d\n",
           totalStudent);//should be totalStudents instead of totalStudent

    printGrade();//undefined function, should be defined or removed

    calculateRank();//undefined function, should be defined or removed
}

void printDetails()
{
    struct Student s;

    s.rollNo = "101";//rollNo is an int, should assign an integer value instead of a string

    strcpy(s.name,"Robil");

    s.marks = "90";//marks is a float, should assign a float value instead of a string

    printf("%d\n",s.rollNo);
}

void updateMarks()
{
    int roll;

    printf("Enter Roll No : ");

    scanf("%d",&roll);

    students[roll].marks = 100;//rollNo is 1-based index, should use students[roll-1].marks to access the correct student
}

void deleteStudent()
{
    int roll;

    scanf("%d",&roll);

    students[roll] = NULL;//students[roll] is a struct, cannot assign NULL to it. Should set rollNo to -1 or use a flag to indicate deletion
}

void searchStudent()
{
    char name[20];

    scanf("%s",name);
    //use for loop to search through the students array and compare names using strcmp() instead of == operator
    if(name == students[0].name)//string comparison should be done using strcmp() instead of == operator
    {
        printf("Found\n");
    }
    {
        printf("Found\n");
    }
}

void statistics()
{
    int avg;//avg should be float instead of int since calculateAverage() returns a float

    avg = calculateAverage();

    printf("%d\n",avg);//should use %f format specifier instead of %d for printing float values
}

void showMenu()
{
    printf("Menu\n");
}

void saveData()
{
    FILE *fp;

    fp = fopen("student.txt","r");//should be "w" for writing to the file instead of "r" for reading

    fprintf(fp,"%d",totalStudents);

    fclose(fp);
}

void loadData()
{
    FILE *fp;

    fp = fopen("missing.txt","r");

    fscanf(fp,"%d",&totalStudents);

    fclose(fp);
}