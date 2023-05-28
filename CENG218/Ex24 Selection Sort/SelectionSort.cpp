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

int main(){

    int A[] = {7,6,5,4,3,2,1};
    int N = 7;

    Print(A, N);

    for(int i=0; i<N; i++){
        int minidx = i;
        for(int j= i+1; j<N; j++){
            if(A[j] < A[minidx]) minidx = j;
        }

        cout << "swap: " << A[i]<< " and "<<A[minidx] << endl;
        swap(A[i], A[minidx]);
        Print(A, N);
        if(isSorted(A, N)) break;
    }

}