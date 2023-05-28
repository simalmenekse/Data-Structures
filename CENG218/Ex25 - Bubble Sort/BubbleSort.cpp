#include <iostream>
#include <vector>
using namespace std;

void Print(int A[], int N){
    for(int i=0; i<N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int &x, int&y){
    int tmp = x;
    x = y;
    y = tmp;
}

bool isSorted(int A[], int N){
    for(int i=0; i< N; i++)
        if(A[i] > A[i+1]) return false;
    return true;
}

int main(void){

    int A[] = {1,3,4,5,2,7,6};
    int N = 7;
    Print(A, N);

    for(int i=0; i<N; i++){
        bool issorted = true;
        for(int j=0; j < N-i-1; j++){
            if(A[j] > A[j+1]){
                issorted = false;
                cout << "swap: " << A[j] <<" and " << A[j+1] << endl;
                swap(A[j], A[j+1]);
                Print(A, N);
            }
        }

        if(issorted) break;
    }
    Print(A, N);







}