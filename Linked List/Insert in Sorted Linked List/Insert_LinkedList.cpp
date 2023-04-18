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

void SortedInsert(Node *p, int x){
    Node *t, *q=NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(head == NULL)
        head = t;
    else{
        while(p && p->data < x)
        {
            q = p;
            p->next;
        }
        if(p==head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next=t;
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
    Display(p);
    cout<<endl;
    SortedInsert(p, 10);
    Display(p);


    return 0;
}