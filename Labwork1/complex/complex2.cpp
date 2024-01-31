#include<iostream>
#include "complex2.h"
using namespace std;

int main()
{
    Complex obj1(5.0,7.0);
    Complex obj2(3.0,6.0);
    Complex obj3 = obj1+obj2;
    Complex obj4 = obj1*obj2;
    cout<<"Sum: "<<obj3<<endl;
    cout<<"Product: "<<obj4<<endl;
    return 0;
}
