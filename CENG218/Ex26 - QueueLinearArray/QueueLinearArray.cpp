#include <iostream>
using namespace std;

template <class T>
class QueueLinearArray{
    private:
        T* Data;
        int Front, Rear, Capacity;
    public:
        QueueLinearArray(int cap=10){
            Data = new T[cap];
            Front = Rear = -1; //Empty
            Capacity = cap;
        }
        const T& front(){return Data[Front];}
        const T& back(){return Data[Rear];}
        bool isEmpty(){return Front==-1;}
        bool isFull(){return Capacity == count();}
        int count(){
            if(isEmpty()) return 0;
            return (Rear-Front) + 1;
        }
        bool push(T&X){
            if(isFull()) return false; //means add operation failed
            if(Rear == Capacity-1){
                for(int i = Front; i<=Rear; i++)
                    Data[i-Front] = Data[i];
                Rear = Rear - Front;
                Front = 0;
            }
            Rear = Rear + 1;
            Data[Rear] = X;
            if(Front = -1) Front = Front + 1;
            return true;
        }

        bool pop(){
            if(isEmpty()) return false;
            if(count() == 1)
                Front = Rear = -1;
            else Front = Front + 1;
            return true;
        }

        void Print(){
            for(int i=0; i<Capacity; i++)
                cout << Data[i] << " ";
            cout << "Front: " << Front << " Rear: " << Rear << " count: " << count() << endl;
        } 
};


int main(){

    QueueLinearArray<int>Q1(5);
    int myint = 99;
    int mysint = 12;
    Q1.Print();
    Q1.push(myint);
    Q1.push(mysint);
     Q1.Print();
    cout << "last element: " << Q1.back() << endl;
    cout << "first elemet: " <<  Q1.front() << endl;
    Q1.pop();
    Q1.Print();

    for(int i=50; i < 55; i++)
        Q1.push(myint = i+1);
    Q1.Print();

    return 0;
}