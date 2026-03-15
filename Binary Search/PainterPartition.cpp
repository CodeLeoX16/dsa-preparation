#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Check if boards can be painted by k painters
// such that no painter paints more than sol units
bool ispossible(vector<int>& arr, int k, int sol) {

    int blen = 0;   // length painted by current painter
    int c = 1;      // number of painters used

    for (int i = 0; i < arr.size(); i++) {

        // Single board exceeds allowed limit
        if (arr[i] > sol)
            return false;

        // Assign board to next painter if limit exceeded
        if (blen + arr[i] > sol) {
            c++;
            blen = arr[i];

            // More painters needed than available
            if (c > k)
                return false;
        }
        // Continue with current painter
        else {
            blen += arr[i];
        }
    }
    return true;
}

// Find minimum time using Binary Search on Answer
int paintermintime(vector<int>& arr, int k) {

    // Not enough boards
    if (arr.size() < k)
        return -1;

    int st = 0;                                     // minimum time
    int end = accumulate(arr.begin(), arr.end(), 0); // maximum time
    int ans = -1;

    while (st <= end) {
        int mid = (st + end) / 2;  // current time limit

        if (ispossible(arr, k, mid)) {
            ans = mid;        // store valid answer
            end = mid - 1;    // try smaller time
        } else {
            st = mid + 1;     // increase time
        }
    }
    return ans;
}

int main() {

    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;

    cout << "Minimum time required = "
         << paintermintime(boards, painters) << endl;

    return 0;
}
