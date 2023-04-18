#include <iostream>
#include <vector>

using namespace std;

void printAr(vector<int>& A) {
   for(int i=0;i< A.size() ;i++)
      cout << "A["<<i<<"]="<<A[i]<<endl;
}

void insertAr(vector<int>& myar, int pos, int val) {
   myar.push_back(-1);
   for(int i= myar.size()-2;i>pos;i--)
      myar[i+1]= myar[i];
   myar[pos+1]= val; //insert 6 iafter 2
}

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for(int i=0;i<v.size();i++)
     os<<"v["<<i<<"]="<<v[i]<<endl;
  return os;
}

int main( ) {
   vector<int> myar= { 1,5,2,7,3,8};
   vector<char> mystr= {'A','h','m','e','t'};

   cout<<mystr<<endl;

   cout<<"size:"<< myar.size()<<" capacity:"<< myar.capacity()<<endl;
   //printAr(myar);
   cout<<myar<<endl;

   //insert 6 after 2
   insertAr(myar,2,6);

   printAr(myar);
   return 0;
}