#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <string>
using namespace std;
void insSort(vector<int>& A) {
   for(int i=1; i< A.size(); i++) {
      int tmp= A[i]; // item to be inserted
      int j= i-1; // compare with last element
      while(j>=0 && tmp<A[j]) {
         A[j+1]= A[j];
	 j--;
      }
      A[j+1]= tmp;
   }
}

bool isSorted(vector<int>& V) {
   for(int i=0; i< V.size( )-1 ;i++)
      if(V[i]>V[i+1]) return false; // not sorted
   return true;
}

void generateRandomVector(vector<int>& V, int N){
   cout << "Random vector: " << N << endl;
   for(int i=0;i<N;i++){
      V.push_back(rand()%100);
   }
}

void generateReverseVector(vector<int>& V, int N) {
   cout<<"ReverseVector:"<<N<<endl;
   for(int i=0;i<N;i++)
     V.push_back(N-i);
}

ostream&operator<<(ostream &os, vector<int>&V){
   for(int i=0; i<V.size();i++)
      os<<V[i]<<" ";
   return os;
}

int main(int argc, char *argv[]) {
   vector<int> dummy;
   vector<int> A;
   vector<int> B;
   vector<int> C;
   srand(time(NULL));


   return 0; 
}