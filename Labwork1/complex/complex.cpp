#include<iostream>
using namespace std;

class Complex{
	public:
	int real;
	int img;
	friend istream& operator >>(istream& is,Complex& obj){
		cout<<"Enter the real part:";
		is>>obj.real;
		cout<<"Enter the imaginary part:";
		is>>obj.img;
		return is;
	}
	friend ostream& operator <<(ostream& os,Complex& obj){
		cout<<obj.real<<"+"<<obj.img<<"i"<<endl;
		return os;
    }
 	friend Complex operator +(Complex x, Complex y ){
	Complex result1;
	result1.real=x.real+y.real;
	result1.img=x.img+y.img;
	return result1;
	}
	friend Complex operator *(Complex x, Complex y ){
	Complex result2;
	result2.real=(x.real*y.real)-(x.img*y.img);
	result2.img=(x.real*y.img)+(y.real*x.img);
	return result2;
	}
	void operator --(){
	cout<<"Complement of the Complex Number is:"<<real<<"-"<<img<<"i"<<endl;

	}
};
int main(){
	Complex obj1,obj2;
	cout<<"Complex Number 1"<<endl;
	cin>>obj1;
	cout<<"Complex Number 2 "<<endl;
	cin>>obj2;
	cout<<"Complex Number1 is:"<<obj1;
	cout<<"Complex Number2 is:"<<obj2;
	Complex obj3;
	obj3=obj1+obj2;
	cout<<"Sum:"<<obj3;
	Complex obj4;
	obj4=obj1*obj2;
	cout<<"Product:"<<obj4;
	--obj1;
	--obj2;
	
	return 0;
}

