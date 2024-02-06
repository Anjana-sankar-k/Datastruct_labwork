#include "array.cpp"

int main(){

	Array<int> myArray;
	myArray.insert_at_end(5);
	myArray.insert_at_end(6);
	myArray.insert_at_end(7);
	myArray.insert_at_end(8);
	myArray.insert_at_end(3);
	myArray.insert_at_pos(2,2);
	myArray.insert_at_begin(9);
	cout<<"Inserted array: "<<endl;
	cout<<myArray;
	myArray.delete_at_end();
	myArray.delete_at_begin();
	myArray.delete_at_pos(3);
	cout<<"deleted array"<<endl;
	cout<<myArray;
	cout<<myArray.binarysearch(10);
	myArray.quicksort(1,5);
	cout<<endl;
	cout<<"Insertion"<<endl;
	cout<<myArray;

	Array<float> myfArray;
	myfArray.insert_at_end(3.5);
	myfArray.insert_at_end(5.5);
	myfArray.insert_at_end(6.3);
	myfArray.insert_at_pos(7.4,1);
	myfArray.insert_at_begin(1.0);
	cout<<"Inserted array "<<endl;
	cout<<myfArray;
	myfArray.delete_at_end();
	cout<<"Deleted array"<<endl;
	cout<<myfArray;
	cout<<myfArray.linearsearch(5.5);
	cout<<myfArray;
	myfArray.insertion_sort();
	cout<<"Sorted array"<<endl;
	cout<<myfArray;

	return 0;
}
