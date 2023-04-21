#include <iostream>
#include <vector>

using namespace std;

#define NR 3
#define NC 4

template<class T>
ostream& operator<<(ostream& os, vector<T>& V){
    for(int i=0; i< V.size(); i++)
        os << V[i] << " ";
    os << endl;
    return os;
};

int main(){

    vector<vector<int>> C;
    for(int i=0; i<NR;i++){
        vector<int>B;
        for(int j=0;j<NC;j++)
            B.push_back(-1);
        
        C.push_back(B);
    }

    cout << C;

    return 0;
}