#include <iostream>

using namespace std;

int main(void){

    int A[] = {1,2,3,4,5};
    cout << "start A[0]: " << &A[0] << endl;
    cout << "start A[1]: " << &A[1] << endl;
    cout << "start A[2]: " << &A[2] << endl;

    cout << "start A[2]: " <<  A+2 << endl; //A+8 means 8 *sizeof(int)

    int i, *pi;
    pi = &i;
    cout << "&i:" << &i << " pi: " << pi << endl;
    cout <<"pi+1: " << pi+1 << endl;

    pi = A;

    cout << "pi: " << pi << endl;
    cout << "A: " << A << endl;

    pi = pi+1;
    cout << "pi+1: " << pi << endl;

    for(pi=A; pi <= &A[4]; pi++)
        cout << *pi << " ";
    
    cout << endl;

    return 0;
}
