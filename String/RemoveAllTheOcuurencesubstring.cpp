// You are given:

// A string s

// A substring part

// Your task is to repeatedly remove all occurrences of part from s
// until part no longer exists in the string.
// Input
// s = "daabcbaabcbc"
// part = "abc"
//output="dab"
#include<iostream>
using namespace std;
string RemoveAllTheOcuurenceOfSubstring(string &s,string &part){
    while(s.find(part)!=-1){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    string s="daabcbaabcbc";
    string part="abc";
    cout<<RemoveAllTheOcuurenceOfSubstring(s,part);
}