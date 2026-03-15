#include<iostream>
#include<stack>
using namespace std;
void InsertStackRemainSorted(stack<int>&s,int val){
    if(s.empty()){
        s.push(val);
        return;

    }
    if(val>=s.top()){
        s.push(val);
        return;
    }
    int top=s.top();
    s.pop();
    InsertStackRemainSorted(s,val);
    s.push(top);
}
int main() {
    stack<int> s;

    // Stack sorted in descending order (top → bottom)
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);   // top

    int val = 25;

    InsertStackRemainSorted(s, val);

    cout << "Stack after inserting " << val << " (top → bottom):" << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
