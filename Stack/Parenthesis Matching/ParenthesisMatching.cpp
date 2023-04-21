#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Node{
    public:
        char data;
        Node *next;
};

Node *top = NULL;
void push(char x){
    Node *temp = new Node;

    if(temp==NULL)
        cout << "Stack is Full!" << endl;
    else{
        temp->data =x;
        temp->next = top;
        top = temp;
    }
}

char pop(){
    char x=-1;
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

int isBalanced(string exp){
    int i;
    for(i=0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            if(top==NULL)
                return 0;
            pop();
        }
    }

    if(top==NULL)
        return 1;
    else
        return 0;
}

 int main(void){

    string exp ="((a+b) * (c-d)))";
    cout << isBalanced(exp);


    return 0;
 }