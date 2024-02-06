#include<iostream>
#include<ostream>

using namespace std;
template <class T>
class Array{
	int LB,UB;
	T A[100];


  public:
  	Array();
  	Array(int,int,T[]);
  	void insert_at_end(T);
	void insert_at_begin(T);
	void insert_at_pos(T,int);
	void delete_at_end();
	void delete_at_begin();
	void delete_at_pos(int);
	int linearsearch(T);
	int binarysearch(T);
	void selection_sort();
	void bubble_sort();
	void insertion_sort();
	int partition(int,int);
	void quicksort(int,int);
	void swap(int,int);


 	template <class F>
  	friend ostream& operator<<(ostream&, Array<F> );
};
