#include<iostream>
using namespace std;
bool isPalindrome(string &s){
    int n=s.length();
    int st=0,end=n-1;
    if (s.empty())return true;
    while(st<=end){
        if(s[st]!=s[end])return false;
        else {
            st++;
            end--;
        }
    }
    return true;
}
int main(){
    string s="madamea";
    cout<<isPalindrome(s);
}