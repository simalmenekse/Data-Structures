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


  int Delete(Node *p, int index)
  {
      Node *q;
      int x =-1;
      if(index <1 || index > count(p))
          return -1;
      if(index==1)
      {
          q = head;
          x = head->data;
          head = head->next;
          delete q;
          return x;
      }
      else
      {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        delete p;
        return x;
      }
      
  }

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
    Display(p);
    Delete(p, 3);
    cout << endl;
    Display(p);


    return 0;
}