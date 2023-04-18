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

int count(Node *p)
{
    int l=0;
    while(p){
        l++;
        p= p->next;
    }
    return l;
}

int isSorted(Node *p)
{
    int x = INT32_MIN;
    while(p != NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p=p->next;
    }
    return 1;
}

int main(void){
    int A[] = {3,5,7,10,15, 2};
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
    if(isSorted(p)) 
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;
        
    Display(p);



    return 0;
}