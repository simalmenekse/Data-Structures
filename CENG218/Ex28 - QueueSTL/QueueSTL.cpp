#include <iostream>
#include <queue>
using namespace std;

void Print(queue<int>& Q){

    if(!Q.empty()){
        cout << "first element: " << Q.front() << " ";
        cout << "last element: " << Q.back() << " ";
    }
    else
        cout << "Queue is empty, ";
    cout << " size: " << Q.size() << endl;

}

int main(){

    queue<int> Q1;
    int myint = 99;
    Print(Q1);
    Q1.push(myint);
    Print(Q1);

    Q1.pop();
    Print(Q1);

    for(int i =50; i<55; i++)
        Q1.push(myint=i+1);
    
    Q1.pop();
    Print(Q1);
    Q1.push(myint=99);
    Print(Q1);


    return 0;
}