#include"array.h"

template <class T>
Array<T>::Array(){
	LB=1;
	UB=0;
	mid = 0;
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
float Array<T>::binarysearch(T key) {
	int p = LB;
	int q = UB;
	cout<<p<<" "<<q<<endl;

    while (p <= q) {
        mid = (p + q) / 2;
		cout<<"inital value for mid"<<mid;
        if (A[mid] > key) {
            q = mid - 1;
        } else if (A[mid] < key) {
            p = mid + 1;
        } else {
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

template <class T>
int Array<T>::partition( int LB,int UB){
	int j=LB-1;
	int pivot=A[UB];
	int i=LB;
	while(i<UB){
		if(A[i]>pivot){
			j=j+1;
			swap(A[i],A[j]);
		}
		i+=1;
	}
	swap(A[j+1],A[UB]);
	return j+1;
}

template <class T>
void Array<T>::quicksort(int LB,int UB){
	cout<<*this;
	if (LB<=UB){
		int p=partition(LB, UB);
			quicksort(LB,p-1);
			quicksort(p+1,UB);

		}
	}

template <class T>
void Array<T>::mergesort(T A[], T B[], T C[],int A_LB, int A_UB, int B_LB, int B_UB){
    int k = 0;
    int j = B_LB;
    int i = A_LB;
    for(; i<= A_UB && j<=B_UB; ++k){
        if(A[i]<B[j]){
            C[k] = A[i++];
        }
        else if (B[j]<A[i]){
            C[k] = B[j++];
        }
        else{
            C[k] = B[j++];
            C[++k] = A[i++];
        }
    }
    while (i<=A_UB){
        C[k++] = A[i++];
    }

    while (j<=B_UB){
        C[k++] = B[j++];
    }
}

template <class T>
void Array<T>::rotateClockwise(int k) {
    int n = UB - LB + 1;
    k = k % n;
    if (k < 0) {
        k += n;
    }
    T* temp = new T[n];

    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = A[i];
    }

    for (int i = 0; i < n; ++i) {
        A[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Array<T>::rotateAntiClockwise(int k) {
    int n = UB - LB + 1;
    k = k % n;
    if (k < 0) {
        k += n;
    }
    T* temp = new T[n];

    for (int i = 0; i < n; ++i) {
        temp[i] = A[(i + k) % n];
    }

    for (int i = 0; i < n; ++i) {
        A[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Array<T>::printDistinctElements() {
    int n = UB - LB + 1 ;
    cout << "Distinct Elements: ";
    for (int i = 0; i < n; ++i) {
        bool isDistinct = true;
        for (int j = 0; j < i; ++j) {
            if (A[i] == A[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

template <class T>
void Array<T>::generateFrequencyTable() {
    int n = UB - LB + 1 ;
    cout << "Frequency Table:" << endl;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) {
                ++count;
            }
        }
        bool isCounted = false;
        for (int k = 0; k < i; ++k) {
            if (A[i] == A[k]) {
                isCounted = true;
                break;
            }
        }
        if (!isCounted) {
            cout << A[i] << ": " << count << endl;
        }
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


