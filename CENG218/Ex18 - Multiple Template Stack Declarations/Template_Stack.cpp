#include <iostream>
using namespace std;

class Matrix{};

template<class T>
class Stack{

    private:
        T *data;
        int Top;
        int Capacity;
    public:
        Stack(int sz=10){
            data = new T[sz];
            Capacity = sz;
            Top = -1;
        }

        bool isEmpty(){
            return Top == -1;
        }

        int countElements(){
            return Top+1;
        }
};

int main(int argc, char*argv[]){

    Stack <int> s1(5);
    Stack <string> s2(3);

    Stack <Matrix> *s3 = new Stack<Matrix>();

    if(s1.isEmpty())
        cout << "S1 is empty!" << endl;

    return 0;
}






