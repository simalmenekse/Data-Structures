#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>&A){
    for(int i=0; i<A.size(); i++)
        cout << "A["<<i<<"]="<<A[i] <<endl;
}

void insertArr(vector<int> &myar, int pos, int val){
    myar.push_back(-1);
    for(int i= myar.size() -2 ; i>pos; i--)
        myar[i+1] = myar[i];
     myar[pos+1]= val;  //insert 6 iafter 2
}

template <class T>
ostream &operator <<(ostream &os, vector<T>&v){
    for(int i=0; i<v.size();i++)
        os<<"v["<<i<<"]="<<v[i]<<endl;
    return os;
}

int main(void){
    
    vector<int> myar = {1,5,2,7,3,8};
    vector <char> mystr = {'S','i', 'm','a','l'};

    //cout << mystr;

    cout << "size: " << myar.size() << " capacity: " << myar.capacity() << endl;
    //printArr(myar);

    cout<<myar<<endl;

    insertArr(myar,2,6);

    cout << myar << endl;

    return 0;
}