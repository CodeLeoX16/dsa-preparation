#include <iostream>
#include <vector>
using namespace std;

// Function to find the single non-duplicate element in a sorted array
// In the array, every element appears exactly twice except one element
int findNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    int st = 0, end = n - 1;

    // Binary search loop
    while (st < end) {
        // Find middle index
        int mid = (st + end) / 2;

        // Make mid even (we compare pairs, so start of pair should be even)
        if (mid % 2 == 1) mid--;

        // If the pair is valid (mid and mid+1 are same), search right half
        if (arr[mid] == arr[mid + 1])
            st = mid + 2;
        // Otherwise, the single element is in the left half (including mid)
        else
            end = mid;
    }

    // st will point to the single non-duplicate element
    return arr[st];
}

int main() {
    // Sorted array where every element appears twice except one
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    // Print the single non-duplicate element
    cout << findNonDuplicate(arr);

    return 0;
}
