#include<iostream>
using namespace std;

class Vector{
	public:
	int x,y,z;
	friend istream& operator >>(istream& is,Vector& obj){
		cout<<"Enter the x component:";
		is>>obj.x;
		cout<<"Enter the y component:";
		is>>obj.y;
		cout<<"Enter the z component:";
		is>>obj.z;
		return is;
	}
	friend ostream& operator <<(ostream& os,Vector& obj){
		cout<<"("<<obj.x<<")i(+"<<obj.y<<")j+("<<obj.z<<")k"<<endl;
		return os;
    }
 	friend Vector operator +(Vector a, Vector b){
		Vector result1;
		result1.x=a.x+b.x;
		result1.y=a.y+b.y;
 		result1.z=a.z+b.z;
		return result1;
	}
	friend Vector operator *(Vector a, Vector b){
		Vector result2;
		result2.x=a.x*b.x;
		result2.y=a.y*b.y;
		result2.z=a.z*b.z;
		cout<<"Dot Product is:"<<result2.x+result2.y+result2.z<<endl;
		return result2;
	}
	friend Vector operator ^(Vector a, Vector b){
		Vector result3;

		result3.x=a.y*b.z;
		result3.y=a.x*b.z;
		result3.z=a.x*b.y;
		return result3;
	}

};
int main(){
	Vector obj1,obj2;
	cout<<"Vector 1"<<endl;
	cin>>obj1;
	cout<<"Vector 2"<<endl;
	cin>>obj2;
	cout<<"Vector1 is:"<<obj1;
	cout<<"Vector2 is:"<<obj2;
	Vector obj3;
	obj3=obj1+obj2;
	cout<<"Resultant:"<<obj3;
	Vector obj4;
	obj4=obj1*obj2;
	Vector obj5;
	obj5=obj1^obj2;
	cout<<"Cross Product:"<<obj5;
	return 0;
}
