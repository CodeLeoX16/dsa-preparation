#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
string NormalizeString(string & pattern){
    char starting='a';
    unordered_map<char,char>mapping;
    for(int i=0;i<pattern.size();i++){
        char ch=pattern[i];
        mapping[ch]=starting;
        starting++;

    }
    string ans="";
    for(int i=0;i<pattern.size();i++){
        char ch=pattern[i];
        char mappedch=mapping[ch];
        ans.push_back(mappedch);

    }
    return ans;
}
vector<string>FindReplacePattern(string&pattern,vector<string>&words){
    vector<string>ans;
    string newpattern=NormalizeString(pattern);
    for(int i=0;i<words.size();i++){
        string word=words[i];
        string newword=NormalizeString(word);
        if(newword==newpattern)ans.push_back(word);
    }
    return ans;
}
int main() {
    string pattern = "abb";
    vector<string> words = {"abc", "mee", "aqq", "dkd", "ccc"};

    vector<string> result = FindReplacePattern(pattern, words);

    cout << "Matching words: ";
    for (string &s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}