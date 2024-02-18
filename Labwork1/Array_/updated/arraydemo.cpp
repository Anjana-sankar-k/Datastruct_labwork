#include "array.cpp"

int main() {
    Array<int> myArray;
    myArray.insert_at_end(7);
    myArray.insert_at_end(6);
    myArray.insert_at_end(5);
    myArray.insert_at_end(12);
    myArray.insert_at_end(1);
    myArray.insert_at_end(20);
    myArray.insert_at_end(13);
    myArray.insert_at_end(2);
    myArray.insert_at_pos(9, 2);
    myArray.insert_at_begin(9);
    cout << "INSERTED ARRAY" << endl;
    cout << myArray;
    myArray.delete_at_end();
    myArray.delete_at_begin();
    myArray.delete_at_pos(3);
    cout << "DELETED ARRAY" <<endl;
    cout << myArray;
    cout << "QUICK SORT "<<endl;
    myArray.quicksort(1,7);
    cout<<myArray;
    cout << "Result " << myArray.binarysearch(7)<<endl;


    Array<float> myfArray;
    myfArray.insert_at_end(5.5);
    myfArray.insert_at_end(6.3);
    myfArray.insert_at_pos(7.4, 1);
    myfArray.insert_at_begin(1.0);
    cout << "Inserted array " << endl;
    cout << myfArray;
    myfArray.delete_at_end();
    cout << "Deleted array" << endl;
    cout << myfArray;
    cout << "INSERTION SORT" << endl;
    myfArray.insertion_sort();
    cout << myfArray;
    cout << "Result: " << myfArray.binarysearch(5.5)<<endl;
    myfArray.generateFrequencyTable();
    myfArray.rotateClockwise(1);
	cout<<myfArray;
	myfArray.printDistinctElements();

    return 0;
}
