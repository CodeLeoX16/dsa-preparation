#include<iostream>
#include<stack>
using namespace std;
void InsertSorted(stack<int>&s,int val){
    if(s.empty()|| s.top()>=val){
        s.push(val);
        return;
    }
    int top=s.top();
    s.pop();
    InsertSorted(s,val);
    s.push(top);
}
void sort(stack<int>&s){
    if(s.empty())return;
    int top=s.top();
    s.pop();
    sort(s);
    InsertSorted(s,top);
}
void print(stack<int>s){
    cout<<"the prited stack:"<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(60);
    s.push(25);
    s.push(50);
    s.push(8);
    print(s);
    sort(s);
    print(s);
    
}