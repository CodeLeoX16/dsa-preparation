#include<iostream>
#include<stack>
using namespace std;
void pushAtButoom(stack<int>&s,int val){
     if(s.empty()){
        s.push(val);
        return;
     }
     int top=s.top();
     s.pop();
     pushAtButoom(s,val);
     s.push(top);
}

void print(stack<int>s){
    cout<<"the printed stack"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void reverseSatck(stack<int>&s){
     if(s.empty()){
        cout<<"stack is empty"<<endl;
        return;
     }
     int top=s.top();
     s.pop();
     reverseSatck(s);
     pushAtButoom(s,top);
}
int main(){
    stack<int>s;
    reverseSatck(s);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    print(s);
    reverseSatck(s);
    print(s);
}