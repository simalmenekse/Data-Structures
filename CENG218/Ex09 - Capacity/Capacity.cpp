#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
   std::vector<int> V1;
   for(int i=0;i<100;i++){
      V1.push_back(i);
      std::cout << "size: " << V1.size() << " capacity: " << V1.capacity() << std::endl;
   }

   for(int i=0; i<100; i++){
      std::cout << V1[V1.size()-1] << " " << V1.back() <<" size: " << V1.size() << " cap: " << V1.capacity() << std::endl;
      V1.pop_back();
   }
   return 0; 
}