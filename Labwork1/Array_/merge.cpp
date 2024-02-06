#include<iostream>
using namespace std;

void mergesort(int A[], int B[], int C[], int A_LB, int A_UB, int B_LB, int B_UB) {
    int k = 0, i = A_LB, j = B_LB;

    while (i <= A_UB && j <= B_UB) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else if (B[j] < A[i]) {
            C[k++] = B[j++];
        } else {
            C[k++] = B[j++];
            C[k++] = A[i++];
        }
    }

    while (i <= A_UB) {
        C[k++] = A[i++];
    }

    while (j <= B_UB) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[6] = {1, 2, 3, 4, 5, 6};
    int B[4] = {7, 8, 9, 10};
    int C[10];  // Allocate memory for the merged array

    mergesort(A, B, C, 0, 5, 0, 3);

    for (int i = 0; i < 10; i++) {
        cout << C[i] << " ";
    }
    cout<<endl;

    return 0;
}
