#include<iostream>
#include<vector>
using namespace std;
bool IsomorphicString(string s ,string t){
    int s_to_t[256]={0};
    int t_to_s[256]={0};
    for(int i=0;i<s.length();i++){
        if(s_to_t[s[i]]==0 && t_to_s[t[i]]==0){
            s_to_t[s[i]]=t[i];
            t_to_s[t[i]]=s[i];

        }else{
            if(t_to_s[t[i]]!=s[i]|| s_to_t[s[i]]!=t[i])return false;
        }
    }
    return true;
}
int main() {
    string s = "paper";
    string t = "title";

    if (IsomorphicString(s, t))
        cout << "Isomorphic\n";
    else
        cout << "Not Isomorphic\n";

    return 0;
}