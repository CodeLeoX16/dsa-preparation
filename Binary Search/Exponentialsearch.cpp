#include <iostream>
#include <vector>
using namespace std;

/*
    Binary Search function
    ---------------------------------
    Searches for 'target' in the array
    between index 'st' and 'end'.
    Returns the index if found, else -1.
*/
int Bs(vector<int>& arr, int st, int end, int target) {
    while (st <= end) {
        // Calculate middle index
        int mid = (st + end) / 2;

        // If target found, return index
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search left half
        if (arr[mid] > target) {
            end = mid - 1;
        }
        // If target is larger, search right half
        else {
            st = mid + 1;
        }
    }
    // Target not found
    return -1;
}

/*
    Exponential Search function
    ---------------------------------
    First finds a range where the target
    may exist by jumping in powers of 2.
    Then applies Binary Search in that range.
*/
int exponentialsearch(vector<int>& arr, int target) {
    int n = arr.size();

    // If the first element itself is the target
    if (arr[0] == target)
        return 0;

    int i = 1;

    // Increase index exponentially until
    // value exceeds target or array ends
    while (i < n && arr[i] < target) {
        i = i * 2;
    }

    // Perform Binary Search in the found range
    return Bs(arr, i / 2, min(i, n - 1), target);
}

/*
    Main function
    ---------------------------------
    Demonstrates exponential search.
*/
int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int target = 12;

    int index = exponentialsearch(arr, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
