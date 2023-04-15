#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

    void Display(Node *p){
        if(p != NULL){
            cout<<p->data<<"->" << flush;
            Display(p->next);
        }   
    }

    Node *LSearch(Node *p, int key){ //Linear Search
       
        Node *q;

        while(p != NULL){
            if(key == p->data)
                return p;
            p = p->next;

        }

        return NULL;
    }

    Node *LSearch_R(Node *p, int key){ // Recursive Linear Search
        if(p==NULL)
            return NULL;
        if(key==p->data)
            return p;
        return LSearch_R(p->next, key);
    }

};


int main(void){
    int A[] = {3,5,7,10,15};
    Node *head = new Node;

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
    p->Display(p);
    cout << endl;
    temp = p->LSearch(p, 3);
    if(temp)
        cout << "Key is Found: " << temp->data;
    else
        cout << "Key is not found!" << endl;

    return 0;
}