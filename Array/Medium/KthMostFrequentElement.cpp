#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

static bool cmp(pair<int,int>a ,pair<int,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
    int kthMostFrequent(vector<int>& arr, int k) {
        // Implement logic to find kth most frequent element
        //unordered map
        unordered_map<int,int>mp;
        for(int num:arr){
            mp[num]++;
        }
        //now add element with ther frequency
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        // if uniqu elment less than k
        if(v.size()<k)return -1;
        sort(v.begin(),v.end(),cmp);
        return v[k-1].first;
    }
int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    cout << "Enter the value of k: ";
    cin >> k;
    int result = kthMostFrequent(arr, k);

    if (result != -1) {
        cout << "The " << k << "rd most frequent element is: " << result << endl;
    } else {
        cout << "There are less than " << k << " unique elements in the array." << endl;
    }
    return 0;
}