#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findMode(const vector<int>& arr) {
        unordered_map<int, int> mp;

        for (int x : arr) {
            mp[x]++;
        }

        int maxFreq = 0;
        int ans = arr[0];

        for (auto it : mp) {
            int num = it.first;
            int freq = it.second;

            if (freq > maxFreq) {
                maxFreq = freq;
                ans = num;
            }
            else if (freq == maxFreq && num < ans) {
                ans = num;
            }
        }

        return ans;
    }
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int mode = findMode(arr);
    cout << "The mode of the array is: " << mode << endl;
    return 0;
}