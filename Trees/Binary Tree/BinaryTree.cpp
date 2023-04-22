#include <iostream>
#include <string>
#include "QueueCpp.h"

using namespace std;

class Tree{
    public:
        Node *root;

        Tree(){root=NULL;}
        void CreateTree();
        void Preorder(Node* p);
        void Postorder(Node *p);
        void Inorder(Node *p);
        void LevelOrder(Node *root);
        int Height(Node *root);
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of: " << p->data << endl;
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter the right child of: " << p->data << endl;
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
    
}

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int Tree::Height(Node *root){
    int x=0, y=0;
    if(root==0)
        return 0;
    x =Height(root->lchild);
    y = Height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

void Tree::LevelOrder(Node *root){
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }

        if(root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
    
}

int main(){

    Tree t;
    t.CreateTree();
    t.Preorder(t.root);
    cout<< endl;
    t.Inorder(t.root);
    cout << endl;
    t.Postorder(t.root);
    cout << endl;
    t.LevelOrder(t.root);

    return 0;
}