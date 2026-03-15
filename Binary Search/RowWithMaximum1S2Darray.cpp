#include <iostream>
#include <vector>
using namespace std;

// Function to find the row with maximum 1s in a row-wise sorted binary matrix
int RowWithMaxOnes(vector<vector<int>>& arr) {
    int n = arr.size();       // Number of rows
    int m = arr[0].size();    // Number of columns
    int ans = -1;             // Store index of row with maximum 1s
    int min1sColIdx = m;      // Column index of first 1 in the row with max 1s

    for (int i = 0; i < n; i++) {
        int st = 0, end = m - 1;
        int firstIdx = -1;    // Store index of first 1 in current row

        // Binary search to find the first 1 in the current row
        while (st <= end) {
            int mid = (st + end) / 2;
            if (arr[i][mid] == 1) {
                firstIdx = mid;
                end = mid - 1;  // Search left side for an earlier 1
            } else {
                st = mid + 1;   // Move right
            }
        }

        // If this row has the first 1 earlier than previous rows, it has more 1s
        if (firstIdx != -1 && firstIdx < min1sColIdx) {
            min1sColIdx = firstIdx;
            ans = i;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    cout << "Row with maximum 1s: " << RowWithMaxOnes(arr) << endl;
    return 0;
}
