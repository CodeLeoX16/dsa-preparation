#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Allpermuhelper(string &s,int i){
    if(i>=s.length()){
        cout<<s<<" ";
        return; 
    }
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        Allpermuhelper(s,i+1);
        swap(s[i],s[j]);

    }
}

int main(){
    string s="abc";
    int i=0;
    Allpermuhelper(s,i);
}