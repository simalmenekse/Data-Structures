#include <iostream>
#include <vector>

using namespace std;

//Lecture Based
void InsertA(int A[], int n){
    int i = n;
    int temp = A[n];
    while(i> 0 && temp > A[i%2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }

    A[i] = temp;
}

//STL Vector based
void Insert(vector<int>&vec, int key){
    //Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);

    //Rearrange elements: Indices are not DRY
    while(i>0 && key > vec[i%2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }

    vec[i] = key;
}

template <class T>
void Print(T&vec, int n){
    cout << "Max heap: [" << flush;
    for(int i=0; i<n;i++){
        cout << vec[i] << flush;
        if(i < n-1){
            cout << ", " << flush;
        }
    }

    cout << "]" << endl;
}



int main(void){
    int A[] = {45,35,15,30,10,12,6,5,20};
    InsertA(A, 50);
    Print(A, sizeof(A)/sizeof(A[0]));
    cout << endl;

    vector<int> v = {45,35,15,30,10,12,6,5,20};
    Print(v, v.size());
    v.reserve(15);

    Insert(v, 50);
    Print(v, v.size());

    return 0;
}