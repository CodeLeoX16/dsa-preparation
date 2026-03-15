 #include <iostream>
#include <vector>
using namespace std;

/*
    Binary Search in a given range
*/
int bs(vector<int>& infiniteArray, int st, int end, int target) {
    while (st <= end) {
        int mid = st + (end - st) / 2;

        // compare with mid, not 0
        if (infiniteArray[mid] == target)
            return mid;

        if (infiniteArray[mid] > target)
            end = mid - 1;
        else
            st = mid + 1;
    }
    return -1;
}

/*
    Unbounded Search (YOUR approach)
*/
int Unboundedsearch(vector<int>& infiniteArray, int target) {

    // check first element
    if (infiniteArray[0] == target)
        return 0;

    int i = 1;

    // exponential range expansion
    while (infiniteArray[i] < target) {
        i = i * 2;
    }

    // binary search in the found range
    return bs(infiniteArray, i / 2, i, target);
}
int main() {
    vector<int> infiniteArray = {2, 5, 7, 10, 14, 18, 21, 25, 30, 35, 40};
    int target = 21;

    int result = Unboundedsearch(infiniteArray, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
