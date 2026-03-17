#include<iostream>
#include<vector>
#include <vector>
#include <algorithm>
using namespace std;

    int highestfreq(const vector<int>& arr){
        int n = arr.size();
        if(n == 0) return -1;

        int curr = 1;
        int maxcount = 1;
        int ans = arr[0];

        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]){
                curr++;
            } else {
                curr = 1;
            }

            if(curr > maxcount){
                maxcount = curr;
                ans = arr[i];
            }
        }
        return ans;
    }

    int lowestfreq(const vector<int>& arr){
        int n = arr.size();
        if(n == 0) return -1;

        int curr = 1;
        int mincount = n + 1; // start with max possible
        int ans = arr[0];

        for(int i = 1; i <= n; i++){  // note: i<=n to handle last element
            if(i < n && arr[i] == arr[i-1]){
                curr++;
            } else {
                // check current frequency
                if(curr < mincount){
                    mincount = curr;
                    ans = arr[i-1];
                }
                curr = 1; // reset for next element
            }
        }
        return ans;
    }

    pair<int, int> highestAndLowestFrequency(vector<int> arr) {
        if(arr.empty()) return {-1, -1};
        sort(arr.begin(), arr.end());  // important step

        int most = highestfreq(arr);
        int least = lowestfreq(arr);
        return {most, least};
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
    pair<int, int> result = highestAndLowestFrequency(arr);
    cout << "The element with the highest frequency is: " << result.first << endl;
    cout << "The element with the lowest frequency is: " << result.second << endl;
    return 0;


}
