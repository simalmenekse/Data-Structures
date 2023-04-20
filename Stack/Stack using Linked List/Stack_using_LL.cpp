#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

Node *top = NULL;
void push(int x){
    Node *temp = new Node;

    if(temp==NULL)
        cout << "Stack is Full!" << endl;
    else{
        temp->data =x;
        temp->next = top;
        top = temp;
    }
}

int pop(){
    int x=-1;
    Node *temp = new Node;
    if(top==NULL)
        cout << "Stack is Empty!" << endl;
    else{
        temp = top;
        top = top->next;
        x=temp->data;
        delete temp;
    }

    return x;
}

void Display(){
    Node *p;
    p = top;
    while(p!=NULL){
        cout << p->data << "|" ;
        p=p->next;
    }
    cout << endl;
}
 int main(void){

    push(10);
    push(20);
    push(30);

    Display();

    cout << pop() << endl;

    Display();


    return 0;
 }