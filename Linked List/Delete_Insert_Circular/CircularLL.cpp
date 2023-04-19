#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

};    
Node *head =  new Node;
void create(int A[], int n){
    int i;
    Node *t, *last;
    head->data =A[0];
    head->next=head;
    last=head;

    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;

    }
}
 int count(Node *p){
        int c=0;
        do
        {
            c++;
            p=p->next;
        } while (p!=head);

        return c;
        
    }

void Display(Node *h)
{
    do{
        cout << h->data << "->";
        h = h->next;
    }while(h!=head);
    cout<<endl;
}

void RDisplay(Node *h){
    static int flag=0;
    if(h!= head || flag==0)
    {
        flag=1;
        cout << h->data << "->";
        RDisplay(h->next);
    }
    flag=0;
}
void Insert(Node *p, int index, int x){
    Node *t;
    int i;

    if(index <0 || index > count(p))
        return;

    if(index==0)
    {
        t = new Node;
        t->data = x;
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)p=p->next;
                p->next = t;
                t->next=head;
                head=t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next=t;
    }
    
}

int Delete(Node *p, int index){
    Node *q;
    int i, x;

    if(index<0 || index > count(head))
        return -1;
    if(index==1)
    {
        while(p->next != head)p=p->next;
        x = head->data;
        if(head==p)
        {
            delete head;
            head = NULL;
        }
        else{
            p->next = head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
        q = p->next;
        p->next=q->next;
        x = q->data;
        delete q;
    }

    return x;

}
int main(void){
    int  A[] = {2,3,4,5,6};
    create(A, 5);

    Delete(head, 1);
    Insert(head,2,10);
    RDisplay(head);


    return 0;
}