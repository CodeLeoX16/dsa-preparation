#include <iostream>
#include <vector>
#include <cmath> // for abs()
using namespace std;

// Function to find k closest elements to x in a sorted array
vector<int> KClosest(vector<int>& arr, int x, int k) {
    int st = 0;                   // Start of binary search window
    int end = arr.size() - k;      // End of window; we only need to check up to n-k

    // Binary search to find the starting index of the k closest elements
    while (st < end) {
        int mid = (st + end) / 2;

        // Compare absolute differences at mid and mid+k
        // If mid+k is closer to x, move the window right
        if (abs(x - arr[mid]) > abs(x - arr[mid + k])) {
            st = mid + 1;
        } else { // Otherwise, move the window left
            end = mid;
        }
    }

    // Return k elements starting from the found index
    return vector<int>(arr.begin() + st, arr.begin() + st + k);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    int x = 3;

    vector<int> res = KClosest(arr, k, x);

    cout << "The " << k << " closest elements to " << x << " are: ";
    for (int num : res) cout << num << " ";
    cout << endl;

    return 0;
}
