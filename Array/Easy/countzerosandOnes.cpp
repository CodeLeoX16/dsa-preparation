#include<iostream>
#include<vector>
using namespace std;

pair<int, int> countZerosAndOnes(const vector<int>& nums) {
    int n = nums.size();
    int nZero = 0;
    int nOne = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) nZero++;
        if (nums[i] == 1) nOne++;
    }
    return {nZero, nOne};
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    pair<int, int> result = countZerosAndOnes(nums);

    cout << "Number of 0s: " << result.first << endl;
    cout << "Number of 1s: " << result.second << endl;

    return 0;
}