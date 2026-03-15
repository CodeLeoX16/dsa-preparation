#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include<stack>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;
    Stack(int capacity){
        arr=new int[capacity];
        top=-1;
        size=capacity;
    }
    void push(int val){

        if(top==size-1){
            cout<<"stack is full"<<endl;
        }else{
            arr[++top]=val;
        }

    }
    int  getTopElement(){

        if(top==-1){
        cout<<"stack is empty";
        return -1;

        }else{
            return arr[top];
        }

    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty";

        }
        else{
            top--;
        }
    }
    int getsize(){
        return top+1;
    }
    bool isempty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
    void print(){
        cout<<"the stack is:"<<endl;
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    Stack s(100);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.print();
    cout<<"top element is:"<<endl;;
     cout<<s.getTopElement()<<endl;;
     s.pop();
    s.print();
    cout<<"top element is:"<<endl;;
    cout<<s.getTopElement()<<endl;;
    cout<<"the size of the stack is:"<<endl;
    cout<<s.getsize();
}