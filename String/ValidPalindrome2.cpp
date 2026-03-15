#include<iostream>
using namespace std;
bool isPalindrome(string &s,int i,int j){
    while(i<j){
     if(s[i]!=s[j])return false;
     else{
        i++;
        j--;
     }
    }
     return true;
}
bool isplaindrome2(string &s){
    int n=s.length();
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]){
            return isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1);
        }else{
            i++;
            j--;
        }
    }
    return true;
}
int main(){
    string s="abca";
    cout<<isplaindrome2(s);
}
