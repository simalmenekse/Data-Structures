#include <iostream>
#include <stack>
#include <list>

using namespace std;

stack <int> SysStack;
list <int> List1;

void func(){
    int p1=-1, p2=-1, p3=-1;
    cout << "func() has been called!" << endl;
    p1 = List1.back();
    List1.pop_back();
    p2 = List1.back();
    List1.pop_back();
    p3 = List1.back();
    List1.pop_back();

    int sum = p1+p2+p3;
    cout << "Returning from function value: " << p1 <<"+" << p2 << "+" << p3 << "=" << sum << endl;
    List1.push_back(sum);
    return;
}

int main(int argc, char*argv[]){
    List1.push_back(3); //[3]
    List1.push_back(9); // [3,9]
    List1.push_front(1); // [1,3,9]

    func();
    int result = List1.front();
    List1.pop_front();

    cout << "Returned sum: " << result << endl;
}