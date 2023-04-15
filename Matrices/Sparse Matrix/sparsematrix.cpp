#include <iostream>
using namespace std;


struct Element
{
    int i, j, x;
};

struct Sparsematrix
{
    int m, n, num;
    struct Element *e;
};

void create(Sparsematrix *s){
    int i;
    cout << "Enter dimensions: ";
    cin >> s->m >> s->n;
    cout << "Enter num of nonzero: ";
    cin >> s->num;
    s-> e = new Element[s->num];
    cout << "Enter all nonzero elements: ";
    for(i=0;i<s->num;i++){
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
    }

}

void display(Sparsematrix s){
    int i, j, k=0;
    for(i=0; i<s.m; i++ )
    {
        for(j=0; j<s.n; j++){
            if(i == s.e[k].i && j == s.e[k].j)
                cout << (s.e[k++].x) << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

}

int main(void){
    Sparsematrix A;
    create(&A);
    display(A);

    return 0;
}