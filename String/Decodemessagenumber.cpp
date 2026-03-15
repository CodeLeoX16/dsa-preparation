#include<iostream>
using namespace std;
string DecodeMessage(string&message){
    string ans="";
    for(char ch:message){
        ans.push_back('a'+(ch-'1'));
    }
    return ans;
}
int main(){
    string message="123456";
    cout<<DecodeMessage(message);
}