#include<iostream>
#include<vector>
using namespace std;
string LongestCommonPrefix(vector<string>arr){
    string ans="";
    int i=0;
    while(true){
       char cur_ch=0;
       for(auto str:arr){
       if(i>=str.size()){
        cur_ch=0;
        break;
       }
       if(cur_ch==0){
        cur_ch=str[i];
       }
       if(cur_ch!=str[i]){
        cur_ch=0;
        break;
       }
    }
    if(cur_ch==0)break;
    ans.push_back(cur_ch);
    i++;
    }
    return ans;
}
int main() {
    vector<string> arr = {"flower", "flow", "flight"};

    cout << "Longest Common Prefix: "
         << LongestCommonPrefix(arr) << endl;

    return 0;
}