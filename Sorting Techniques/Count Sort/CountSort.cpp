#include <iostream>
#include <string>
using namespace std;

template <class T>
void Print(T&vec, int n, string s){
    cout << s << ":[" << flush;
    for(int i=0;i<n;i++){
        cout << vec[i] << flush;
        if(i <n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;

}

int Max(int A[], int n){
    int max = INT32_MIN;
    for(int i=0;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }

    return max;
}

void CountSort(int A[], int n){
    int max = Max(A, n);

    //Create count Array
    int *count = new int[max+1];

    //Initialize count array with 0
    for(int i=0; i<max+1;i++){
        count[i] = 0;
    }

    //Update count array values based on A values
    for(int i=0;i<n;i++){
        count[A[i]]++;
    }

    //Update A with sorted elements
    int i=0, j=0;
    while(j< max+1){
        if(count[j]>0){
            A[i++] = j;
            count[j]--;
        }
        else{
            j++;
        }
    }

    delete []count;

}

int main(void){
    int A[] = {2,5,8,12,3,6,7,10};
    int n = sizeof(A)/sizeof(A[0]);

    Print(A,n,"A: ");
    CountSort(A,n);
    Print(A,n,"Sorted A: ");
}