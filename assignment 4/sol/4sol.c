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

int findAccountIndex(int accNo);
float generateAverage();
void createAccount();
void displayAccounts();
void depositMoney();
void withdrawMoney();
void generateReport();
void saveAccounts();
void loadAccounts();
void statistics();
void deleteAccount();

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
        printf("6. Statistics\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        if(scanf("%d",&choice)!=1)
        {
            while(getchar()!='\n');
            continue;
        }
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
                statistics();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}

int findAccountIndex(int accNo)
{
    for(int i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accNo == accNo)
        {
            return i;
        }
    }
    return -1;
}

float generateAverage()
{
    if(totalAccounts == 0)
    {
        return 0.0f;
    }
    float total = 0;
    for(int i=0;i<totalAccounts;i++)
    {
        total += accounts[i].balance;
    }
    return total / totalAccounts;
}

void createAccount()
{
    if(totalAccounts >= 10)
    {
        printf("Database Full\n");
        return;
    }
    static int accountCounter = 1000;
    accounts[totalAccounts].accNo = accountCounter++;
    printf("Enter Name : ");
    scanf("%29s", accounts[totalAccounts].name);
    printf("Enter Balance : ");
    scanf("%f",&accounts[totalAccounts].balance);
    totalAccounts++;
}

void displayAccounts()
{
    if(totalAccounts == 0)
    {
        printf("No accounts\n");
        return;
    }
    for(int i=0;i<totalAccounts;i++)
    {
        printf("\nAccount No : %d\n", accounts[i].accNo);
        printf("Name : %s\n", accounts[i].name);
        printf("Balance : %.2f\n", accounts[i].balance);
    }
}

void depositMoney()
{
    int acc;
    float amount;
    printf("Enter Account Number : ");
    scanf("%d",&acc);
    printf("Enter Amount : ");
    scanf("%f",&amount);
    int index = findAccountIndex(acc);
    if(index == -1)
    {
        printf("Account not found\n");
        return;
    }
    accounts[index].balance += amount;
    printf("Deposited\n");
}

void withdrawMoney()
{
    int acc;
    float amount;
    printf("Enter Account Number : ");
    scanf("%d",&acc);
    printf("Enter Amount : ");
    scanf("%f",&amount);
    int index = findAccountIndex(acc);
    if(index == -1)
    {
        printf("Account not found\n");
        return;
    }
    if(accounts[index].balance >= amount)
    {
        accounts[index].balance -= amount;
        printf("Withdrawn\n");
    }
    else
    {
        printf("Insufficient Balance\n");
    }
}

void generateReport()
{
    if(totalAccounts == 0)
    {
        printf("No accounts\n");
        return;
    }
    float total = 0;
    float highest = accounts[0].balance;
    float lowest = accounts[0].balance;
    for(int i=0;i<totalAccounts;i++)
    {
        total += accounts[i].balance;
        if(accounts[i].balance > highest)
        {
            highest = accounts[i].balance;
        }
        if(accounts[i].balance < lowest)
        {
            lowest = accounts[i].balance;
        }
    }
    printf("Total Balance = %.2f\n", total);
    printf("Average Balance = %.2f\n", generateAverage());
    printf("Highest = %.2f\n", highest);
    printf("Lowest = %.2f\n", lowest);
    printf("Total Accounts = %d\n", totalAccounts);
    saveAccounts();
}

void statistics()
{
    if(totalAccounts == 0)
    {
        printf("No accounts\n");
        return;
    }
    float average = generateAverage();
    printf("Average Balance = %.2f\n", average);
}

void saveAccounts()
{
    FILE *fp;
    fp = fopen("accounts.txt","w");
    if(fp == NULL)
    {
        printf("Error\n");
        return;
    }
    fprintf(fp,"%d\n",totalAccounts);
    for(int i=0;i<totalAccounts;i++)
    {
        fprintf(fp,"%d %s %.2f\n",accounts[i].accNo,accounts[i].name,accounts[i].balance);
    }
    fclose(fp);
}

void loadAccounts()
{
    FILE *fp;
    fp = fopen("accounts.txt","r");
    if(fp == NULL)
    {
        return;
    }
    fscanf(fp,"%d",&totalAccounts);
    for(int i=0;i<totalAccounts;i++)
    {
        fscanf(fp,"%d %s %f",&accounts[i].accNo,accounts[i].name,&accounts[i].balance);
    }
    fclose(fp);
}

void deleteAccount()
{
    int accNo;
    printf("Enter Account Number : ");
    scanf("%d",&accNo);
    int index = findAccountIndex(accNo);
    if(index == -1)
    {
        printf("Account not found\n");
        return;
    }
    for(int j=index;j<totalAccounts-1;j++)
    {
        accounts[j] = accounts[j+1];
    }
    totalAccounts--;
    printf("Account deleted\n");
}
