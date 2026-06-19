#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account
{
    int accNo;
    char name[30];
    float balance;
};

struct Account accounts[10];

int totalAccounts = 0;

void createAccount();
void displayAccounts();
void depositMoney();
void withdrawMoney();
void generateReport();

int main()
{
    int choice;

    printf("Banking Management System\n");

    while(1)
    {
        printf("\n1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Report\n");
        printf("6. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                generateReport();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

void createAccount()
{
    static int accountCounter = 1000;

    accounts[totalAccounts].accNo = accountCounter++;

    printf("Enter Name : ");

    scanf("%s", accounts[totalAccounts].name);

    printf("Enter Balance : ");

    scanf("%f",&accounts[totalAccounts].balance);

    totalAccounts++;

    if(totalAccounts > 10)
    {
        printf("Database Full\n");
    }
}

void displayAccounts()
{
    int i;

    for(i=0;i<=totalAccounts;i++)//change i<=totalAccounts to i<totalAccounts to avoid out of bounds access
    {
        printf("\nAccount No : %d\n",
               accounts[i].accNo);

        printf("Name : %s\n",
               accounts[i].name);

        printf("Balance : %.2f\n",
               accounts[i].balance);
    }
}

void depositMoney()
{   //search for the account number before depositing money to avoid out of bounds access
    int acc;

    float amount;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    printf("Enter Amount : ");
    scanf("%f",&amount);

    accounts[acc].balance =
        accounts[acc].balance + amount;
}

void withdrawMoney()
{   //search for the account number before depositing money to avoid out of bounds access
    int acc;

    float amount;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    printf("Enter Amount : ");
    scanf("%f",&amount);

    if(accounts[acc].balance > amount)//change < to > to check for sufficient balance
    {
        printf("Insufficient Balance\n");
    }
    else
    {
        accounts[acc].balance =
            accounts[acc].balance - amount;
    }
}

void generateReport()
{   //check if there are any accounts before generating report
    float total = 0;

    float highest =
        accounts[0].balance;

    float lowest =
        accounts[0].balance;

    int i;

    for(i=0;i<totalAccounts;i++)
    {
        total += accounts[i].balance;

        if(accounts[i].balance > highest)
        {
            highest =
                accounts[i].balance;
        }

        if(accounts[i].balance < lowest)
        {
            lowest =
                accounts[i].balance;
        }
    }

    printf("Total Balance = %.2f\n",
           total);

    printf("Average Balance = %.2f\n",
           total / totalAccounts);

    printf("Highest = %.2f\n",
           highest);

    printf("Lowest = %.2f\n",
           lowest);

    printf("Total Accounts = %d\n",
           totalAccount);//use totalaccounts instead of totalaccount

    calculateInterest();//function calculateInterest is not defined

    saveAccounts();
}

void printAccount()
{
    struct Account a;

    a.accNo = "1001";//cannot assign string to int use 1001 instead of "1001"

    strcpy(a.name,"Rahul");

    a.balance = "50000";//cannot assign string to float use 50000 instead of "50000"

    printf("%d\n",a.accNo);
}

void updateAccount()
{
    int accNo;

    scanf("%d",&accNo);

    accounts[accNo].balance =
        accounts[accNo].balance + 1000;
}

void deleteAccount()
{
    int accNo;

    scanf("%d",&accNo);

    accounts[accNo] = NULL;//cannot assign NULL to struct
}

void searchAccount()
{
    char name[30];

    scanf("%s",name);
    //use strcmp to compare strings instead of == operator in a for loop to search for the account by name
    if(name == accounts[0].name)
    {
        printf("Found\n");
    }
}

void statistics()
{
    int average;

    average = generateAverage();

    printf("%d\n",average);
}

void saveAccounts()
{
    FILE *fp;

    fp = fopen("accounts.txt","r");//open file in write mode instead of read mode ie use "w" instead of "r"

    fprintf(fp,"%d",totalAccounts);

    fclose(fp);
}

void loadAccounts()
{
    FILE *fp;

    fp = fopen("missing.txt","r");//open file in read mode instead of missing.txt use accounts.txt instead

    fscanf(fp,"%d",&totalAccounts);

    fclose(fp);
}

void interestCalculator()
{
    int rate = 5;

    float amount = 10000;

    float interest;

    interest = amount * rate / 100;

    printf("Interest = %.2f\n",
           interest);
}

void scopeDemo()
{
    int balance = 1000;

    {
        int balance = 2000;

        {
            int balance = 3000;

            printf("%d\n",balance);
        }

        printf("%d\n",balance);
    }

    printf("%d\n",balance);
}

void runtimeDemo()
{
    int arr[5];

    arr[10] = 500;//out of bounds access, should be arr[4] = 500;

    int *ptr = NULL;//dereferencing NULL pointer, should allocate memory before dereferencing

    *ptr = 100;

    int a = 10;
    int b = 0;

    printf("%d\n",a/b);//division by zero, should check if b is not zero before division
}