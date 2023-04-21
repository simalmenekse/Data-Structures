#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Node{

    private:
        char data;
        Node *next;
        
    public:
        
        Node(char val){
            data = val;
            next = nullptr;
        }

        void Print();

        void Append(Node *LN){
            this->next = LN;
        }
};

Node *first = 0, *last = 0;
void Node::Print(){
    while(first){
        cout<<first->data << "->";
        first = first->next;
    }
    cout << endl;
}

int main(int argc, char *argv[]){

    char *A;
    cin >> *A;
    for(int i=0; i<strlen(A); i++){
        Node *temp = new Node(A[i]);
        if(first==0)
            first = last = temp;
        else{
            last->Append(temp);
            last = temp;
        }
    }
    first->Print();

}