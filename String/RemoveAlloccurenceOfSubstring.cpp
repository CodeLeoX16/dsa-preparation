#include<iostream>
using namespace std;
string OccurenceSubstring(string &s,string sub){
    int n=s.length();
    while(s.find(sub)!=-1){
        s.erase(s.find(sub),sub.length());
    }
    return s;


}
int main() {
    string s = "daabcbaabcbc";
    string sub = "abc";

    cout << OccurenceSubstring(s, sub);
}