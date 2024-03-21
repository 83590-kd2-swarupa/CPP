/*
Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();
*/
#include<iostream>
using namespace std;

struct Date
{
    int dd;
    int mm;
    int yyyy;

    void initDate()
    {
        dd = 01;
        mm = 01;
        yyyy = 2000;
    }

    void acceptDateFromConsole()
    {
        cout<<"Enter the date - "<<endl;
        cin>> dd >> mm >>yyyy;
    }

    void printDateOnConsole()
    {
        cout<<"Date: "<<dd<<"-"<<mm<<"-"<<yyyy<<endl;
        if(isLeapYear())
        cout<<"This is a Leap Year"<<endl;
        else
        cout<< "This is not a Leap Year"<<endl;
        
    }
    bool isLeapYear()
    {
        if((yyyy%4 == 0 && yyyy%100 !=0) || (yyyy%400 == 0))
        return true;
        else
        return false;
    }
};

int main()
{
    struct Date d;
    d.initDate();
    int choice;

    do{
        cout<<"0.Exit\n1.Accept Date\n2.Display Date"<<endl;
        cout<<"Enter Your Choice:";
        cin>>choice  ;

        switch(choice)
        {
            case 0:
            cout<<"Thank you for using this app..."<<endl;
            break;
            case 1:
            d.acceptDateFromConsole();
            break;
            case 2:
            d.printDateOnConsole();
            break;
            default:
            cout<<"Incorrect Choice!! Please enter correct choice"<<endl;

        }

    }while(choice!=0);

    return 0;

}