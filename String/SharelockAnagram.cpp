#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int sharelockAndAnagram(string &s){
    int n=s.length();

    int ans=0;
    unordered_map<string,int>substring_count;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string substr=s.substr(i,j);
            sort(substr.begin(),substr.end());
            substring_count[substr]++;
        }
    }
    for(auto it:substring_count){
        int count=it.second;
        ans+=count*(count-1)/2;

    }
    return ans;

}

int main() {
    string s;
    cin >> s;                // input string
    cout << sharelockAndAnagram(s);
    return 0;
}