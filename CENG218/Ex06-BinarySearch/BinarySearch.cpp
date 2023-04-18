#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>&A, int x){
   int first=0, last = A.size() -1;
   while(first <= last)
   {
      int mid = (first+last) /2;
      if(A[mid] == x)
         return mid;
      if(A[mid] > x)
         last = mid-1;
      else
         first = mid + 1;
   }

   return -1; //Not Found!

}


int main( ) {
   vector <int> A = {3,4,6,8,9};

   cout<<"searching 6: pos="<< BinarySearch(A,6) << endl;
   cout<<"searching 4: pos="<< BinarySearch(A,4) << endl;
   cout<<"searching 5: pos="<< BinarySearch(A,5) << endl;
   cout<<"searching 3: pos="<< BinarySearch(A,3) << endl;
   cout<<"searching 9: pos="<< BinarySearch(A,9) << endl;
   cout<<"searching 15: pos="<< BinarySearch(A,15) << endl;
   cout<<"searching -3: pos="<< BinarySearch(A,-3) << endl;

   return 0; 
}