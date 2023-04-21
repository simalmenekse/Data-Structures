#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node *next;
};

template <class T>
class LinkedList{

    private:
        Node<T> *first;
        Node<T> * last;
        int Cnt;
    public:
        LinkedList(){
            first=last=0;
            Cnt = 0;
        }

        bool isEmpty(){return first==0;}
        int getCnt(){return Cnt;}

        void append(T elt){
            Node<T> *tmp = new Node<T>();
            tmp->data = elt;
            if(isEmpty())
                first = last = tmp;
            else{
                last->next = tmp;
                last = tmp;
            }

            Cnt = Cnt +1;
        }

        void insert(T elt, int i); //i=0 first

        void deleteFirst(T& elt){ //assume LL is not empty
            elt = first->data;
            first = first->next;
            if(first==0)
                last = 0;
            Cnt = Cnt - 1;
        }
        void deleteLast(T &elt){
            elt = last->data;
            Cnt = Cnt -1;
            if(Cnt==0){
                first = last = 0;
                return;
            }
            Node<T> *prev = first;
            for(Node <T> *tmp=first; tmp->next!=last;tmp=tmp->next){
                prev = tmp->next;
            }

            prev->next = 0;
            last = prev;
        }

        void deleteNth(T&elt, int n);
        void Print(){
            for(Node<T> *tmp = first; tmp!=0; tmp= tmp->next)
                cout << tmp->data << "|";
            cout << endl;
        }
};

template <class T>
class StackLL{
    private:
        LinkedList<T> *data;
        int Top();
    public:
        StackLL(){
            data = new LinkedList<T>;
        }
        bool isEmpty(){return data->isEmpty();}
        int cntElts(){return data->getCnt();}
        void pop(T&x){data->deleteLast(x);}
        void push(T x){data->append(x);}
        void Print(){data->Print();}
};

int main(int argc, char *argv[]){

    StackLL<int>S1;

    if(S1.isEmpty())
        cout << "S1 is empty!" << endl;
    
    S1.push(5);
    S1.push(7);
    S1.Print();
    int x, y;
    S1.pop(x);
    if(x==7)
        cout << "S1.pop() works: " << x << endl;
    else
        cout << "S1.pop():" << x << endl;
    
    S1.pop(x);
    if(x==5)
        cout << "S1.pop() works: " << x << endl;
    else
        cout <<"S1.pop():" << x << endl;

    S1.push(3);
    S1.push(5); 
    S1.push(6);
    S1.push(4);
    S1.Print();

    S1.pop(x);//4
    S1.pop(y);//6

    cout <<"x: " << x << " y: " << y << endl;
    S1.push(y-x); // 3 -> 3 5 2
    S1.Print();
    S1.pop(x); // 2
    S1.pop(y); // 5

    S1.push(x*y); // Stack: 3, 10
    S1.Print();

    S1.pop(x); //10
    S1.pop(y); // 3

    S1.push(x+y); //13

    S1.Print();

    return 0;


}





