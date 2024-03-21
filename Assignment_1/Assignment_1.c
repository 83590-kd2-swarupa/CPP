/*
Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);
*/

#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};
    void initDate(struct Date *ptr)
    {
        ptr->day=1;
        ptr->month=1;
        ptr->year=1970;
    }
    
    void acceptDateFromConsole(struct Date *ptr)
    {
    printf("Enter day,month and year:" );
    scanf("%d%d%d", &ptr->day, &ptr->month, &ptr->year);
    }

    void printDateOnConsole(struct Date *ptr)
    {
    printf("DATE: %d-%d-%d\n\n", ptr->day, ptr->month, ptr->year);
    } 



int main()
{
    struct Date d;
    int choice;

    initDate(&d);

    do
    {
        printf("0.Exit\n");
        printf("1.Accept Date\n");
        printf("2.Print Date\n");
        printf("Enter Your Choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
            printf("Thank you.");
            break;

            case 1:
            acceptDateFromConsole(&d);
            break;

            case 2:
            printDateOnConsole(&d);
            break;

            default:
            printf("wrong Choice");
            break;
        } 
    } while (choice!=0);
    
    return 0;
}