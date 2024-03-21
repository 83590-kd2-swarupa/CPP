/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options ->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.
#include<iostream>
using namespace std;
*/
#include <iostream>
using namespace std;

class Volume
{
    private:

    int l;
    int w;
    int h;


    public:

    Volume()
    {
        l=2;
        w=3;
        h=5;

    }
 
    Volume(int value)
    {
        l=value;
        w=value;
        h=value;
    }

    Volume(int l,int w, int h)
    {
        this->l=l;
        this->w=w;
        this->h=h;
    }

   void Vlm()
    {
        cout<< "Volume of box is: "<<l*w*h<<"\n";
    }

};


int main()
{
    Volume v;
    int choice;
   
   do
    {
        cout<<"0.Exit\n";
        cout<<"1.Calculate Volume with default values:-\n";
        cout<<"2.Calculate Volume with length,breadth and height with same value:-\n";
        cout<<"3.Calculate Volume with different length,breadth and height values:-\n";
        cout<<"Enter the choice:";
        cin>>choice;

        switch(choice)
        {
            case 0:
            {
            cout<<"Thank you.";
            }
            break;

            case 1:
            {
                Volume v;
                v.Vlm();
            }    
            break;

            case 2:
            {
                int x;
                cout<<"Enter the values:";
                cin>>x;
                Volume v(x);
                v.Vlm();
            }    
            break;

            case 3:
            {
                int a,b,c;
                cout<<"Enter the values";
                cin>>a>>b>>c;
                Volume v(a,b,c);
                v.Vlm();
            }    
            break;

            default:
            {
                cout<<("wrong Choice");
            }    
        } 
    } while (choice!=0);
    
    return 0;
  
}