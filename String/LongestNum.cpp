#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool comp(string &a ,string &b){
    return a+b>b+a;
}
string longestNum(vector<int>&nums){
       vector<string>Snums;
       for(auto it:nums){
        Snums.push_back(to_string(it));
       }
       sort(Snums.begin(),Snums.end(),comp);
       string ans="";
       for(auto it:Snums){
        ans+=it;
       }
       return ans;
}
int main() {
    int n;
    cin >> n;                 // number of elements

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << longestNum(nums);
    return 0;
}