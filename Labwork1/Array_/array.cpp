#include"array.h"

template <class T>
Array<T>::Array(){
	LB=1;
	UB=0;
}

template <class T>
Array<T>::Array(int LB,int UB,T x[]){
 int i = LB;
 while(i<=UB){
	A[i]=x[i];
	i++;
 }
}

template <class T>
void Array<T>::insert_at_end(T key){
	UB=UB+1;
	A[UB]=key;
}

template<class T>
void Array<T>::insert_at_begin(T key){
	UB = UB+1;
	int k = UB - 1;
	while (k>=LB){
		A[k+1] = A[k];
		k = k-1;
	}
	A[LB] = key;
}

template <class T>
void Array<T>::insert_at_pos(T key, int pos){
	UB = UB + 1;
	int k = UB - 1;
	while(k>=pos){
		A[k+1] = A[k];
		k = k-1;
	}
	A[pos]=key;
}

template<class T>
void Array<T>::delete_at_end(){
	if(UB>=LB){
		UB = UB - 1;
	}
	else{
		cout<<"Array is empty."<<endl;
	}
}

template<class T>
void Array<T>::delete_at_begin(){
	if(UB>=LB){
		for(int k = LB + 1; k<= UB; ++k){
			A[k-1] = A[k];
		}
		UB = UB - 1;
	}
	else{
		cout<<"Array is empty."<<endl;
	}
}

template<class T>
void Array<T>::delete_at_pos(int pos){
	if(pos<LB || pos>UB){
		cout<<"Invalid position"<<endl;
	}

	for(int k = pos;k<UB;++k){
		A[k] = A[k+1];
	}
	UB = UB - 1;
}

template<class T>
int Array<T>::linearsearch(T target){
	for (int k = 0; k<UB;++k){
		if(A[k] ==target){
			return k;
		}
	}
	return -1;
}

template<class T>
int Array<T>::binarysearch(T key){

	while(LB<UB){
		int mid = LB+UB/2;
		if (A[mid] > key){
			UB = mid - 1;
		}
		else if (A[mid]<key){
			LB = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

template<class T>
void Array<T>::swap(int p, int q){
	T temp = A[p];
	A[p] = A[q];
	A[q] = temp;
}

template<class T>
void Array<T>::selection_sort(){
	int i,j;
	for(i=LB;i<UB;++i){
		int min = i;
		for(j=i+1;j<UB;j++){
			if (A[j]<A[min]){
				min = j;
			}
		}
		if (min!=i){
			swap(i,min);
		}
	}
}

template<class T>
void Array<T>::bubble_sort(){
	for( int i = LB; i<UB;i++){
		for(int j=LB;j<UB+LB-i-1;j++){
			if (A[j]>A[j+1]){
				swap(j,j+1);
			}
		}
	}
}

template<class T>
void Array<T>::insertion_sort(){
	int n = (UB-LB)+1;
	for (int i = 1; i<n;i++){
		T key = A[i];
	 int j = i-1;

	 while(j>= 0 && A[j]>key){
		A[j+1] = A[j];
		j = j-1;
	 }
	 A[j+1] = key;
	}
}

template<class T>
int Array<T>::partition(int LB, int UB) {
    T pivot = A[UB];

    int i = LB - 1;

    for (int j = LB; j <= UB - 1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[UB]);
    return i + 1;
}


template<class T>
void Array<T>::quicksort(int LB, int UB) {
    if (LB < UB) {
        int index = partition(LB, UB);

        quicksort(LB, index - 1);
        quicksort(index + 1, UB);
    }
}


template <class F>
ostream& operator << (ostream& os,Array<F> M){
	int i;
	os<<endl;
	for (i=M.LB;i<=M.UB;i++){
		os<<M.A[i]<<" ";
	}
	os<<endl;
	return os;
}


