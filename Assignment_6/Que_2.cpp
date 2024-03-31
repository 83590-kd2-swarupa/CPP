/*
Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]
*/

#include<iostream>
using namespace std;

class Product
{
  int id;
  string title;
  double price;

  public:

  virtual void accept()
  {
    cout<<"Enter id:";
    cin>>id;

    cout<<"Enter title:";
    cin>>title;

    cout<<"Enter Price:";
    cin>>price;
  }

  virtual void display()
  {
    cout<<"ID:"<<id<<endl;
    cout<<"TITLE:"<<title<<endl;
    cout<<"PRICE:"<<price<<endl;
  }

  void setPrice(int x)
  {
    if(x==1)
    price = price * 0.9;
    else
    price = price * 0.95;
  }

  double getPrice()
  {
    return price;
  }
};


class Book:public Product
{
    string author;

    public: 

    void accept()
    {
        cout<<"Enter Author:";
        cin>>author;
        Product::accept();
        Product::setPrice(1);
    }

    void display()
    {
        cout<<"The details of book are"<<endl;
        cout<<"AUTHOR:"<<author<<endl;
        Product::display();
        cout<<"The discount price is:"<<Product::getPrice()<<endl;

    }
};

class Tape:public Product
{
    string artist;

    public:

    void accept()
    {
        cout<<"Please Enter the Book deatails"<<endl;
        cout<<"Enter Artist:";
        cin>>artist;
        Product::accept();
        Product::setPrice(2);
    }

    void display()
    {
        cout<<"ARTIST:"<<artist;
        Product::display();
        cout<<"The discount price is:"<<Product::getPrice()<<endl;

    }

};


int main()
{
    int choice;
    Product *arr[3];
    int index=0;
    double total;
    do
    {
        cout<<"0.Exit"<<endl;
        cout<<"1.Enter Book Details"<<endl;
        cout<<"2.Enter Tape Details"<<endl;
        cout<<"3.Total bill of three Products"<<endl;
        cout<<"4.The Product details are:"<<endl;

        cout<<"Enter Choice:";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"Thank You..."<<endl;
                break;
            case 1:
            if (index < 3)
            {
                arr[index] = new Book();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full.." << endl;
            break;
        case 2:
            if (index < 3)
            {
                arr[index] = new Tape();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full.." << endl;
            break;
        

        case 3:
            for (int i = 0; i < index; i++)
                {
                    
                    total +=arr[i]->getPrice();
                };
                cout << "The total price of all 3 products is " << total << endl;
                break;

        case 4:
        for (int i = 0; i < index; i++)
                {
                    arr[i]->display();
                };
                break;
                
        default:
            cout << "Wrong choice.." << endl;
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < index; i++)
        delete arr[i];

    return 0;
}