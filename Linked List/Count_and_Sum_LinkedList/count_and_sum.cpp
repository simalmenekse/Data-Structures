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

    int count(Node *p){
        int c=0;
        while(p!=NULL)
        {
            c++;
            p = p->next;
        }

        return c;
    }

    int r_count(Node *p){ //Recursive Count Function
        if(p == NULL)
            return 0;
        else
            return count(p->next) + 1;
    }

    int add(Node *p){
        int sum=0;
        while(p!=NULL){
            sum = sum + p->data;
            p = p->next;

        }

        return sum;
    }

    int r_add(Node *p){ //Recursive Add Function
        if(p==0)
            return 0;
        else
            return r_add(p->next) + p->data;
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
    cout<<endl;
    cout << p->count(p) << endl;
    cout << p->r_count(p) << endl;
    cout << p->add(p) << endl;
    cout << p->r_add(p) << endl;


    return 0;
}