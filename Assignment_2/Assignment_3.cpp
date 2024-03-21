/*
Q3. Write a class Address with data members (string building, string street, string city ,int pin)
Implement constructors, getters, setters, accept(), and display() methods.
Test the class functunalities by creating the object of class and calling all the functions.
*/

#include<iostream>
using namespace std;

class Address
{
private:
    string building;
    string street;
    string city;
    int pin;

public:
Address() //constructor
{
    cout<<"Parameterless Constructor"<<endl; 
    building ="Madhuban Society";
    street ="Sinhagadh Road";
    city ="Pune";
    pin =411030;
    // cout<<" "<<building<<", "<<street<<endl;
    // cout<<" "<<city<<", "<<pin<<endl;
    
}

Address(string building,string street,string city, int pin) //constructor
{
    
    this->building = building;
    this->street = street;
    this->city = city;
    this->pin = pin;
    // displayAddress();
    
}

void acceptAddress()
{
    cout<<"Accept the address"<<endl;
    cout<<"Enter the address details: "<<endl;
    cin>>building>>city>>street>>pin;
}

void setCity(string city) //setter
{
    cout<<"Mutator"<<endl;
    this->city=city;
}

string getCity() //getter
{
    cout<<"Inspector"<<endl;
    return city;
}
void displayAddress()
{
    cout<<building<<","<<street<<endl;
    cout<<city<<","<<pin<<endl;
}
};

int main()
{
  
    Address a;
    a.displayAddress();
    string p,q,r;
    int s;
    cout<<"Enter Details:"<<endl;
    cin>>p>>q>>r>>s;
    Address a1(p,q,r,s);
    a.acceptAddress();
    a1.displayAddress();
    Address a3;
    a3.setCity("Kolhapur");
    a3.displayAddress();
   
    a.getCity();

    return 0;
}