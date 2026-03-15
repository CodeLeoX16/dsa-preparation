#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
string RecogNizeString(string &s){
    char arr[26]={0};
    for(char c:s){
        arr[c-'a']++;
    }
    int max_freq=0;
    char max_freq_char;
    for(int i=0;i<26;i++){
        if(arr[i]>max_freq){
            max_freq=arr[i];
            max_freq_char=i+'a';
        } 
    }

    if(max_freq>(s.length()+1)/2)return "";
    string ans;
    int index=0;
    while(max_freq>0){
        s[index]=max_freq_char;
        max_freq--;
        index+=2;
    }
    arr[max_freq_char-'a']=0;
    for(int i=0;i<26;i++){
        while(arr[i]>0){
            if(index>=s.length())index=1;
            s[index]=i+'a';
            index+=2;
            arr[i]--;
        }
    }
    return s;

}

int main() {
    string s;
    cin >> s;

    string result = RecogNizeString(s);

    if (result == "")
        cout << "Not possible to reorganize" << endl;
    else
        cout << result << endl;

    return 0;
}