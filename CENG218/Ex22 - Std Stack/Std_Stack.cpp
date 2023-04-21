#include <iostream>
#include <stack>
using namespace std;

stack<int> SysStack;

void func(){
    int p1=-1, p2=-1, p3=-1;
    cout << "The func() has been called!" << endl;
    p1 = SysStack.top();
    SysStack.pop();
    p2 = SysStack.top();
    SysStack.pop();
    p3 = SysStack.top();
    SysStack.pop();

    int sum = p1 + p2 + p3;
    cout << "Returning from function value: " << p1 <<"+" << p2 << "+" << p3 << "=" << sum << endl;
    SysStack.push(sum);
    return;
}

int main(int argc, char *argv[]){

    SysStack.push(3);
    SysStack.push(9);
    SysStack.push(1);
    func();
    int result = SysStack.top();
    SysStack.pop();
    cout << "Returned sum: " << result << endl;
}