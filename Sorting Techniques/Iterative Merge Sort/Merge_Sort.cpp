#include <iostream>
using namespace std;

template <class T>
void Print(T & vec, int n, string s){
    cout << s << ": [" << flush;
    for(int i=0;i<n;i++){
        cout << vec[i] << flush;
        if(i<n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
}

void Merge(int x[], int y[], int z[], int m, int n){
    int i=0;
    int j=0;
    int k = 0;
    while(i<m && j<n){
        if(x[i]<y[j]){
            z[k++] = x[i++];
        }
        else{
            z[k++] = y[j++];
        }
    }

    while(i<m){
        z[k++] = x[i++];
    }

    while(j<n){
        z[k++] = y[j++];
    }
}

void MergeSingle(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while(i<=mid && j<=high){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while(i<mid)
        B[k++] = A[i++];
    
    while(j <= high)
        B[k++] = A[j++];

    for(int i=low; i<=high;i++)
        A[i] = B[i];
}

void ItreativeMergeSort(int A[], int n){
    int p;
    for(p=2; p<=n; p=p*2){
        for(int i = 0; i+p-1<n; i = i+p){
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
    }

    if(p/2 < n)
        Merge(A,0,p/2 - 1, n-1);
}



int main(void){

    int A[]= {2,10,18,20,23};
    int m = sizeof(A)/sizeof(A[0]);
    Print(A,m, "A: ");

    int B[] = {4,9,19,25};
    int n = sizeof(B)/sizeof(B[0]);
    Print(B, n, "B: ");

    int r = m+n;
    int C[r];
    Merge(A,B,C,m,n);

    //Print function does not work for variable lenght array C
    cout << "Sorted" << ":[" << flush;
    for(int i=0; i<r;i++){
        cout << C[i] << flush;
        if(i <r-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
    cout << endl;

    int D[] = {2,5,8,12,3,6,7,10};
    Print(D, sizeof(D)/sizeof(D[0]),"D: ");
    MergeSingle(D,0,3,7);
    Print(D,sizeof(D)/sizeof(D[0]), "Sorted D:")



    return 0;
}