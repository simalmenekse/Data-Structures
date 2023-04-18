#include <iostream>
#include <vector>
using namespace std;
void InsSort(vector<int>&A){
   for(int i=0; i<A.size(); i++)
   {
      int tmp = A[i];
      int j= i-1;
      while(j>=0 && tmp<A[j])
      {
         A[j+1] = A[j];
         j--;
      }
      A[j+1] = tmp;
   }
}

bool isSorted(vector <int> &A){
   for(int i=0;i<A.size()-1;i++)
   {
      if(A[i]>A[i+1])
         return false;
      
   }
   return true;
}

int main( ) {
   vector<int> A = {3, 4, 6, 8, 9};
   vector<int> B = {9, 8, 6, 4, 3};
   vector<int> C = {9, 8};

   cout<< "A is sorted:"<< isSorted(A)<<endl;

   cout<< "B is sorted before:"<< isSorted(B)<<endl;
   InsSort(B);
   cout<< "B is sorted after:"<< isSorted(B)<<endl;

   InsSort(C);
   cout<< "C is sorted after:"<< isSorted(C)<<endl;


   return 0; 
}