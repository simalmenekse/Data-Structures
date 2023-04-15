#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

};

Node *head = new Node;
Node *last = new Node;

void Display(Node *p){
    if(p != NULL){
        cout<<p->data<<"->" << flush;
        Display(p->next);
    }   
}

void InsertLast(int x){
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(head == NULL){
        head = last = t;
    }
    else{
        last->next = t;
        last = t;
    }

}


int main(void){
    int A[] = {3,5,7,10,15};
    

    Node *temp;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    for(int i=1; i<sizeof(A)/sizeof(A[0]); i++){

        temp = new Node;

        temp->data = A[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;

    }

    Node *p = head;
    Display(p);
    InsertLast(20);
    cout<<endl;
    Display(p);


    return 0;
}