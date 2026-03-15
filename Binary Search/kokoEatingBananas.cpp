#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Checks if Koko can eat all bananas
    // at speed 'sol' within 'k' hours
    bool ispossible(vector<int>& arr, int k, int sol){
        long long totaltime = 0;

        for(int i = 0; i < arr.size(); i++){
            // Ceiling division for hours per pile
            totaltime += (arr[i] + sol - 1) / sol;

            // If time exceeds allowed hours
            if(totaltime > k)
                return false;
        }
        return true;
    }

    // Returns minimum eating speed
    int kokoEat(vector<int>& arr, int k) {

        int st = 1;  // Minimum speed
        int end = *max_element(arr.begin(), arr.end());
        int ans = end;

        // Binary Search on Answer
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(ispossible(arr, k, mid)){
                ans = mid;        // Possible speed
                end = mid - 1;    // Try smaller
            } else {
                st = mid + 1;     // Increase speed
            }
        }
        return ans;
    }
};

int main() {

    vector<int> arr = {5, 10, 3};
    int k = 4;   // Total hours

    Solution obj;
    cout << obj.kokoEat(arr, k);

    return 0;
}
