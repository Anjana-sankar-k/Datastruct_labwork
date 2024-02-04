#include "array.cpp"

int main(){

	Array<int> myArray;
	myArray.insert_at_end(5);
	myArray.insert_at_end(6);
	myArray.insert_at_end(3);
	myArray.insert_at_pos(2,2);
	myArray.insert_at_begin(9);
	cout<<myArray;
	myArray.delete_at_end();
	myArray.delete_at_begin();
	myArray.delete_at_pos(3);
	cout<<myArray;
	cout<<myArray.binarysearch(10);
	myArray.bubble_sort();
	cout<<myArray;

	Array<float> myfArray;
	myfArray.insert_at_end(3.5);
	myfArray.insert_at_end(5.5);
	myfArray.insert_at_end(6.3);
	myfArray.insert_at_pos(7.4,1);
	myfArray.insert_at_begin(1.0);
	cout<<myfArray;
	myfArray.delete_at_end();
	cout<<myfArray;
	cout<<myfArray.linearsearch(5.5);
	cout<<myfArray;
	myfArray.selection_sort();
	cout<<myfArray;

	return 0;
}
