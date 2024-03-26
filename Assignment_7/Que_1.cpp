/*
Q1. Provide menu driven code for the functionalities:
1. Accept Employee
2. Display the count of all employees with respect to designation
3. Display All Managers
4. Display All Salesman
5. Display All SalesManagers
*/

#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }

    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};


int main()
{
    int choice;
    int ch;
    Employee *arr[10];
    int index=0;
    int counts=0, countm=0, countsm=0;

    do
    {
        cout<<"0. Exit"<<endl;
        cout<<"1. Accept Employee"<<endl;
        cout<<"2. Display the count of all employees with respect to designation"<<endl;
        cout<<"3. Display All Managers"<<endl;
        cout<<"4. Display All Salesman"<<endl;
        cout<<"5. Display All SalesManagers"<<endl;

        cout<<"Enter choice:";
        cin>>choice;

        switch(choice)
        {
            case 0:
            {
                cout<<"Thank You!"<<endl;
            }
            break;

            case 1:
            {
              do
              {
                cout<<"0. Back"<<endl;
                cout<<"1. Manager"<<endl;
                cout<<"2. Salesman"<<endl;
                cout<<"3. SalesManager"<<endl;

                cout<<"Enter Your Choice:";
                cin>>ch;
                
                 switch(ch)
                 {
                    case 0:
                    {
                        cout<<"Back to Choices:"<<endl;
                    }
                    break;

                    case 1:
                    {
                        if (index < 10)
                            {
                                arr[index] = new Manager();
                                arr[index]->accept();
                                index++;
                            }
                        else
                            cout << "Array is full.." << endl;
                    }
                    break;

                    case 2:
                    {
                        if (index < 10)
                            {
                                arr[index] = new Salesman();
                                arr[index]->accept();
                                index++;
                            }
                        else
                            cout << "Array is full.." << endl;
                    }
                    break;

                    case 3:
                    {
                        if (index < 10)
                            {
                                arr[index] = new SalesManager();
                                arr[index]->accept();
                                index++;
                            }
                        else
                            cout << "Array is full.." << endl;
                    }
                    break;

                    default:
                    {
                        cout<<"Wrong Choice:"<<endl;
                    }
                    break;

                 }
            
              } while(ch!=0);
            }
            break;

            case 2:
            {
                for(int i=0;i<index;i++)
                {
                  if(typeid(*arr[i])==typeid(Manager))
                    {
                        countm++;
                    }
                        else if(typeid(*arr[i])==typeid(Salesman))
                            {
                                counts++;
                            }
                                else if(typeid(*arr[i])==typeid(SalesManager))
                                {
                                 countsm++;
                                }
                }

                cout<<"Number of Managers:"<<countm<<endl;
                cout<<"Number of Salaesmans:"<<counts<<endl;
                cout<<"Number of Salesmanagers:"<<countsm<<endl;
            }
            break;

            case 3:
            {
                for(int i=0;i<index;i++)
                    if(typeid(*arr[i])==typeid(Manager))
                    {
                        arr[i]->display();
                    }
            }
            break;

            case 4:
            {
                for(int i=0;i<index;i++)
                    if(typeid(*arr[i])==typeid(Salesman))
                    {
                        arr[i]->display();
                    }
            }
            break;

            case 5:
            {
                for(int i=0;i<index;i++)
                    if(typeid(*arr[i])==typeid(SalesManager))
                    {
                        arr[i]->display();
                    }

            }
            break;

            default:
            {
                cout << "Wrong choice.." << endl;
            }
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < index; i++)
        delete arr[i];

    return 0;
}