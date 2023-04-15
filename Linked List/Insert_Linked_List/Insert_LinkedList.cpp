#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

};

Node *head = new Node;
void Display(Node *p){
    if(p != NULL){
        cout<<p->data<<"->" << flush;
        Display(p->next);
    }   
}

void Insert(int pos, int x){
    Node *t, *p;
    if(pos==0)
    {
        t = new Node;
        t->data = x;
        t->next = head;
        head = t;
    }
    else if(pos>0){
        p = head;
        for(int i=0;i<pos-1 && p; i++){
            p=p->next;
        }
        if(p)
        {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next=t;
        }
    }

}


int main(void){
    int A[] = {3,5,7,10,15};
    

    Node *temp;
    Node *last;

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
    Insert(2,4);
    Display(p);


    return 0;
}