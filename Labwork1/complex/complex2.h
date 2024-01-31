#include<iostream>
using namespace std;

class Complex{
    public:
    float imag,real;
    Complex(){
        imag = 0;
        real = 0;
    }
    Complex(float real,float imag){
        this->imag = imag;
        this->real = real;
    }

    friend ostream& operator<<(ostream& os, Complex c){
        os<<c.real<<" + "<<c.imag<<" i ";
        return os;
    }

    Complex operator +(Complex obj){
        Complex sum;
        sum.real = this->real +obj.real;
        sum.imag = this->imag + obj.imag;
        return sum;
    }

    friend Complex operator * (Complex obj1,Complex obj2){
        Complex product;
        product.real = obj1.real*obj2.real - obj1.imag*obj2.imag;
        product.imag = obj1.real*obj2.imag + obj1.imag*obj2.real;
        return product;
    }

};

