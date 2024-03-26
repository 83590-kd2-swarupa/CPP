/*
Q1. Create a class Date with data memebrs day,month and year.
Create a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Create a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().
(Note - Perform the Association and Inheritance in the above case.)
*/

#include<iostream>
using namespace std;

class Date
{
private:

int day;
int month;
int year;

public:

void acceptDate()
{
    cout<<"Enter Day:"<<endl;
    cin>>day;
    cout<<"Enter month:"<<endl;
    cin>>month;
    cout<<"Enter year:"<<endl;
    cin>>year;
}
void displayDate()
{
    cout<<"Date is:"<<day<<"/"<<month<<"/"<<year<<endl;
}
};

class Person
{
private:
string name;
string address;
Date dob;

public:

void acceptData()
{
    cout<<"Name:";
    cin>>name;
    cout<<"Address:";
    cin>>address;
    cout<<"Enter Date of Birth:"<<endl;
    dob.acceptDate();
}

void displayData()
{
    cout<<"Name:"<<endl;
    cout<<"Address:"<<address<<endl;
    cout<<"Date of Birth:"<<endl;
    dob.displayDate();
}
};

class Employee:public Person
{
int empid;
string dept;
double sal;
Date doj;

public:

void acceptData()
{
    Person::acceptData();
    cout<<"Enter Employee ID:";
    cin>>empid;
    cout<<"Enter Salary:";
    cin>>sal;
    cout<<"Enter Department:";
    cin>>dept;
    cout<<"Enter Date of Joining:"<<endl;
    doj.acceptDate();
    
}

void displayData()
{
    Person::displayData();
    cout<<"Employee ID:"<<empid<<endl;
    cout<<"Salary:"<<sal<<endl;
    cout<<"Department:"<<dept<<endl;
    cout<<"Date of Joining is:"<<endl;
    doj.displayDate();
}
};

int main()
{
    // Person p;
    // p.acceptData();
    // p.displayData();

    // Employee e;
    // e.acceptData();
    // e.displayData();

  Person *ptr=new Employee;
  ptr->acceptData();
  ptr->displayData();

  delete ptr;
  ptr=NULL;

    return 0;
}