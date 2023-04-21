#include <iostream>

using namespace std;

#define NR 3
#define NC 4

int main(){

    int A[NR][NC];

    for(int i=0; i<NR;i++){
        for(int j=0; j< NC; j++)
            cout << "A["<<i<<"]["<<j<<"]=" << A[i][j] << " ";
        cout << endl;
    }

    int **B = new int*[NR];

    for(int i=0; i< NR; i++)
        B[i] = new int[NC+i];
    
    for(int i=0;i<NR;i++){
        for(int j=0; j<NC; j++)
            cout<<"B["<<i<<"]["<<j<<"]=" << B[i][j] << " ";
        cout << endl;
    }


    return 0;

}