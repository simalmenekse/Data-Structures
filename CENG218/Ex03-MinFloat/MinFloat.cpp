#include <iostream>
#include <iomanip>
using namespace std;
int min(int a, int b){
   if(a<b) return a;
   return b;
}
float mmin(float a, float b){
   if(a<b) return a;
   return b;

}
int main( ) {
   cout << setprecision(3);
   cout << "min(3,5): " << mmin(2.5, 3.5) << endl;
   return 0; 
}