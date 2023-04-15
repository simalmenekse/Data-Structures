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

    int Max(Node *p){
        int max = INT32_MIN;
        while(p!=NULL){
            if(p->data > max)
                max = p->data;
            p = p->next;
        }

        return max;
    }

    int r_max(Node *p){
        int x=0;

        if(p==NULL)
            return INT32_MIN;
        x = r_max(p->next);
        if(x > p->data)
            return x;
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
    cout << p->Max(p) << endl;
    cout << p->r_max(p);


    return 0;
}