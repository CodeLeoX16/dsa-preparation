#include<iostream>
#include<vector>
using namespace std;

// Function to find an element in a nearly sorted array
// Nearly sorted means: an element may be at index i, i-1, or i+1
int finedelenearbysorted(vector<int>& arr, int target) {
    int n = arr.size();

    // Start and end pointers for binary search
    int st = 0, end = n - 1;

    // Binary search loop
    while (st <= end) {

        // Calculate middle index
        int mid = (st + end) / 2;

        // Check middle element
        if (arr[mid] == target)
            return mid;

        // Check left neighbor (make sure index is valid)
        if (mid - 1 >= st && arr[mid - 1] == target)
            return mid - 1;

        // Check right neighbor (make sure index is valid)
        if (mid + 1 <= end && arr[mid + 1] == target)
            return mid + 1;

        // If target is smaller, search left half (skip two elements)
        if (arr[mid] > target)
            end = mid - 2;
        // If target is larger, search right half (skip two elements)
        else
            st = mid + 2;
    }

    // Target not found
    return -1;
}

int main() {

    // Nearly sorted array
    vector<int> arr = {1, 2, 3, 4, 6, 5, 7, 8};

    // Element to search
    int target = 6;

    // Print index of target
    cout << finedelenearbysorted(arr, target);

    return 0;
}
