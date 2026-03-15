// You are given a string.
// Your task is to repeatedly remove adjacent duplicate characters until no such duplicates remain.
// Input
// "babbar"
// Output
// "br"

#include<iostream>
#include<algorithm>
using namespace std;
string RemoveAlladjacentDuplicate(string &s){
    int n=s.length();
    string ans="";
    for(int i=0;i<n;i++){
        if(ans.empty())ans.push_back(s[i]);
        else if(s[i]!=ans.back())ans.push_back(s[i]);
        else ans.pop_back();
    }
    return ans;


}
int main(){
    string s="babbar";
    cout<<RemoveAlladjacentDuplicate(s);
}
