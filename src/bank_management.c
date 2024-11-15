/*
AU2040014-Jay Patel
AU2040114-ROSHANI NAVDIYA
AU2040175 Pruthviraj Dodiya

password:- project
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int i, j;
int main_exit;
void menu();
struct date
{
    int month, day, year;
};
struct
{

    char name[60];
    int acc_no, age;
    char address[60];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
} add, upd, check, rem, transaction;

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr = fopen("goja.txt", "a");
account_no:
    system("cls");
    printf("    $$$$$$$$$  ADD RECORD   $$$$$$$$$$$$");
    printf("\nEnter the account number:");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %lf %s %f\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the address:");
    scanf("%s", add.address);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    printf("\nType of account:\n  #Saving\n  #Current\n  #Fixed1(for 1 year)\n  #Fixed2(for 2 years)\n  #Fixed3(for 3 years)\n\n  Enter your choice:");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);

    fclose(ptr);
    printf("\nAccount created successfully!");
add_invalid:
    printf("\n\n\n   Enter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
    {
        menu();
    }
    else if (main_exit == 0)
    {
        close();
    }
    else
    {
        printf("\nInvalid!  ");
        goto add_invalid;
    }
}
void view_list()
{
    FILE *view;
    view = fopen("goja.txt", "r");
    int test = 0;
    system("cls");
    printf("\nACC. NO.      NAME         ADDRESS       PHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %lf %s %f", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        printf("\n%6d   %10s      %10s    %.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!  ");
        goto view_list_invalid;
    }
}
void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("goja.txt", "r");
    newrec = fopen("new.txt", "w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %lf %s %f", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the new address:");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.phone, add.acc_type, add.amt);
                system("cls");
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number:");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, upd.phone, add.acc_type, add.amt);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);
    }
    fclose(old);
    fclose(newrec);
    remove("goja.txt");
    rename("new.txt", "goja.txt");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!  ");
    edit_invalid:
        printf("\nEnter  to try again,1 to return to main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 0)
            close();
        else if (main_exit == 2)
            edit();
        else
        {
            printf("\nInvalid!  ");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("goja.txt", "r");
    newrec = fopen("new.txt", "w");

    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %lf %s %f", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmpi(add.acc_type, "Fixed1") == 0 || strcmpi(add.acc_type, "Fixed2") == 0 || strcmpi(add.acc_type, "Fixed3") == 0)
            {
                printf(" \n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                system("cls");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("goja.txt");
    rename("new.txt", "goja.txt");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    transact_invalid:
        printf("\n\n\nEnter 2 to try again,1 to return to main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 2)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 0)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}
void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("goja.txt", "r");
    newrec = fopen("new.txt", "w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %lf %s %f", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %lf %s %f\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);

        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("goja.txt");
    rename("new.txt", "goja.txt");
    if (test == 0)
    {
        printf("\nRecord not found!!      ");
    erase_invalid:
        printf("\nEnter 2 to try again,1 to return to main menu and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
            menu();
        else if (main_exit == 0)
            close();
        else if (main_exit == 2)
            erase();
        else
        {
            printf("\nInvalid!  ");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void see(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    ptr = fopen("goja.txt", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the account number:");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %lf %s %f", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name:");
        scanf("%s", &check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %lf %s %f", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, &add.phone, add.acc_type, &add.amt) != EOF)
        {
            if (strcmpi(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.phone, add.acc_type, add.amt);
            }
        }
    }

    fclose(ptr);
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!  ");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!  ");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {
        system("cls");
        menu();
    }

    else
    {

        system("cls");
        close();
    }
}

void close(void)
{
    printf("\nThank you have a good day");
}

void menu(void)
{
    int choice;
    system("cls");

    printf("\n\n      CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n     $$$$$$$$$$ WELCOME TO THE MAIN MENU $$$$$$$$$$ ");
    printf("\n\n    1.Create new account\n    2.Update information of existing account\n    3.For transactions\n    4.Check the details of existing account\n    5.Removing existing account\n    6.View customer's list\n    7.Exit\n\n\n\n     Enter your choice:");
    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;
    }
}
int main()
{
    char pass[10], password[10] = "project";
    int i = 0;
    printf("\n\n  Enter the password to login:");
    scanf("%s", pass);
    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!");
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nWrong password!!");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {

            system("cls");
            main();
        }

        else if (main_exit == 0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\nInvalid!");
            system("cls");
            goto login_try;
        }
    }
    return 0;
}
