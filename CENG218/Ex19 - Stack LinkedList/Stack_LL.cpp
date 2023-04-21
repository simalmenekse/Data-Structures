#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node{

    private:
        Node *first;
        Node *last;
        int count;
    public:
        Node(){
            first = last = 0;
            count = 0;
        }
        bool isEmpty(){return first==0;}
        int Count(){return count;}
        void append(T elt);
        void insert(T elt, int i); // i=0 first

        void deleteFirst(T &elt);
        void deleteLast(T &elt);
        void deleteNth(T &elt, int n);
};

template <class T>
class StackLL{

    private:
        Node<T> data;
        int Top;
        int Capacity;
        int cnt;
    public:
        StackLL(){
            
        }
        bool isEmpty(){return data.isEmpty();}
        int cntElt(){return cnt;}
        void pop(T& x);
        void push(T& x);

};

int main(int argc, char *argv[]){
    StackLL<int>s1;
    
    if(s1.isEmpty())
        cout << "S1 is Empty!";
}





