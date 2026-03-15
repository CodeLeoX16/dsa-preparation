#include<iostream>
#include<unordered_map>
using namespace std;
void CreateMaping(string &key,unordered_map<char,char>&mapping){
    char starting='a';
    for(int i=0;i<key.size();i++){
        char ch=key[i];
        if(mapping.find(ch)==mapping.end()){
            mapping[ch]=starting;
            starting++;
        }
    }
}
string Usemaping(unordered_map<char,char>&mapping,string&message){
    string ans="";
    for(int i=0;i<message.size();i++){
        char ch=message[i];
        char mapedch=mapping[ch];
        ans.push_back(mapedch);
    }
    return ans;

}

string DecodedMessage(string &message,string key){
    unordered_map<char,char>mapping;
    char ch=' ';
    mapping[ch]=ch;
    CreateMaping(key,mapping);

    string ans=Usemaping(mapping,message);
    return ans;

}

int main() {
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    cout << DecodedMessage(message, key);
}
