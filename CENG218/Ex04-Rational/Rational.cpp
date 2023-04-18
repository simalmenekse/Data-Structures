#include <iostream>
#include <iomanip>
using namespace std;

class Rational{
   private:
      int m_numer;
      int m_denom;
   public:
      //Rational( ) { m_numer=0; m_denom=1; }
      //Rational(int num){m_numer=num; m_denom=1;}
      Rational(int num=0, int den=0)
      {
         if(den==0) throw(0);
         m_numer = num;
         m_denom = den;
      }

      void Print(){
         cout << "("<<m_numer<<"/"<<m_denom<<")";
      }

};

int main( ) {
   Rational R1(3,4), R2(2,1), R3(1,2);
   try{
         cout<<"R1:"; R1.Print( ); cout<<endl;
         cout<<"R2:"; R2.Print( ); cout<<endl;
         cout<<"R3:"; R3.Print( ); cout<<endl;  
   }catch(...)
   {
      cout << "Error! " << endl;
   }

   return 0; 
}