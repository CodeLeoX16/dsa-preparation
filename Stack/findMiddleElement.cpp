#include<iostream>
#include<stack>
using namespace std;
void MiddleElement(stack<int>&s,int count,int size){
    if(count==size/2){
        cout<<s.top();
        return;

    }
    int top=s.top();
    s.pop();
    count++;
    MiddleElement(s,count,size);
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    int size=s.size();
    int count=0;
    MiddleElement(s,count,size);
}