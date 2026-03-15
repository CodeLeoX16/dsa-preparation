#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int countKDifferencePairs(vector<int>& arr, int k) {
    int n=arr.size();
    set<pair<int,int>>unique_pair;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(arr[j]-arr[i])==k){
                int a=min(arr[j],arr[i]);
                int b=max(arr[i],arr[j]);
                unique_pair.insert({a,b});
            }
        }
    }
    return unique_pair.size();
}
int countKDifferencePairsTwopointer(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end()); // Two-pointer approach requires sorted array
    int i = 0, j = 1;
    int n = arr.size();
    set<pair<int,int>> uniquepair;

    while (i < n && j < n) {
        if (i == j) {
            j++;
            continue;
        }
        int diff = arr[j] - arr[i];
        if (diff == k) {
            uniquepair.insert({arr[i], arr[j]});
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else { // diff > k
            i++;
        }
    }

    return uniquepair.size();
}


int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;

    // cout << "Number of k-difference pairs: " << countKDifferencePairs(arr, k) << endl;
    cout << "Number of k-difference pairs: " << countKDifferencePairsTwopointer(arr, k) << endl;
    return 0;
}