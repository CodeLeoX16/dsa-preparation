#include<iostream>
using namespace std;

//we can solve by also sorting two string if they equal then that anagram;
bool isvalidAnagram(string &s1,string &s2){
    //int n=1.length();
    char arr[26]={0};
    for(char c:s1){
        arr[c-'a']++;
    }
    for(char c:s2){
        arr[c-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0)return false;

    }
    return true;


}
int main(){
    string s1="rac";
    string s2="car";
    cout<<isvalidAnagram(s1,s2);
}