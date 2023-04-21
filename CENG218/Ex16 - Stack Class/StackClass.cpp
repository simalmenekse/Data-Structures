#include <iostream>

using namespace std;

class Stack{
    private:
        char *data;
        int top;
        int size;
    public:
        Stack(int sz = 10){
            data = new char[size = sz];
            top = -1;
        }

        ~Stack(){
            delete data;
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top ==  size-1;
        }

        char &Top(){
            return data[top];
        }

        void push(char val){
            top = top +1;
            data[top] = val;
        }

        void pop(){
            top = top-1;
        }
        
        int getElementCount(){
            return top+1;
        }
};

int main(int argc, char *argv[]){
    Stack s1(5);
    for(char *t=argv[1]; *t != 0; t = t+1){
        if(*t == '(')
            s1.push('(');
        if(*t == ')'){
            if(s1.isEmpty()){
                cout << "Mismatched right paranthesis" << endl;
                return -1;
            }
            s1.pop();
        }
    }

    if(s1.isEmpty()){
        cout << "SUCCESS: all left parantheses are matched!" << endl;
        return 0;
    }

    cout << "FAIL: Stack has " << s1.getElementCount() << " left parantheses unmatched!" << endl;


}

