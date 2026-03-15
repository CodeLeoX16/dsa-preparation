#include<iostream>
#include<climits>
#include<stack>
using namespace std;
bool checkSorted(stack<int>&s,int prev){
    if(s.empty())return true;
    int next=s.top();
    if(next>prev){
        return false;
    }else{
        s.pop();

        prev=next;
        return checkSorted(s,prev);

    }
}
int main() {
    stack<int> s;

    // Stack must be sorted in descending order (top → bottom)
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);   // top

    bool ans = checkSorted(s, INT_MAX);

    if (ans)
        cout << "Stack is sorted" << endl;
    else
        cout << "Stack is NOT sorted" << endl;

    return 0;
}