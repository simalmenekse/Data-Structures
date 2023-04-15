#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Diagonal{
    public:
        Diagonal(int n);
        void create();
        int get(int i, int j);
        void set(int i, int j, int x);
        void display();
        ~Diagonal();

        public:
            int *A;
            int n;
};

Diagonal::Diagonal(int n){
    this->n = n;
    A = new int[n];
}

Diagonal::~Diagonal(){
    delete[] A;
}


//Menu driven program for Diagonal Matrix
void Diagonal::create(){
    int x, i , j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >>  x;
            if(i==j)
                A[i-1] = x;
        }
    }
    cout << "Finished creating!";
}

void Diagonal::display(){
    int  i , j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)
                cout << A[i-1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}




int main(void){
    
    int  n, ch, x, i, j;
    cout << "Enter dimension: ";
    cin >> n;
    Diagonal Array(n);
    do{    

        cin >> ch;
        //Display Menu
        switch(ch){
            case 1: //Create
                Array.create();
                break;
            case 2: // Get
                cout << "Enter indices: ";
                cin >> i >> j;
                if(i==j)
                    cout<< Array.A[i-1];
                else 
                    cout << "0 ";
                break;
            case 3: //Set
                cout << "Enter row, column, element";
                cin >> Array.A[i] >> Array.A[j] >> x;
                if(i==j)
                    Array.A[i-1] = x;
                break;
            case 4: //Display
              Array.display();
              break;
        }
    }while(ch!=5);

}