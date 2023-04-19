#include <iostream>
#include <cmath>
#include<stack>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};

Node *head =  new Node;
void create(int A[], int n){
    int i;
    Node *temp, *tail;
    head->data =A[0];
    head->next=nullptr;
    tail=head;

    for(i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;

    }
}

void middleNode1(Node *p){
    int length = 0;
    while(p)
    {
        length++;
        p=p->next;
    }

    int index = int(ceil(length/2.0));
    Node *q = head;
    for(int i=0; i<index-1;i++){
        q=q->next;
    }
    cout << "Middle Element(Method-1): " << q->data << endl;
}

void middleNode2(Node *p){
    Node *q = p;
    while (q)
    {
        q=q->next;
        if(q){
            q=q->next;
        }
        if(q){
            p=p->next;
        }
    }
    
    cout << "Middle Element (Method-2): " << p->data << endl;
}

void middleNode3(Node *p){
    stack<Node*>s;
    while(p)
    {
        s.push(p);
        p=p->next;
    }

    int length = s.size();
    int popLength = int(floor(length/2.0));
    while(popLength){
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-3): " << s.top()->data << endl;

}

int main(void){
    int  A[] = {2,3,4,5,6};
    create(A, 5);
    cout << endl;


    middleNode1(head);
    middleNode2(head);
    middleNode3(head);


    return 0;
}