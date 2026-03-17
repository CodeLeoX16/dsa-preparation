#include<iostream>
#include<vector>
using namespace std;
int searchElementInArray(vector<int>& nums, int target) {
    // Implement the logic to search for an element in the array
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==target) return i;
    }
    return -1; // Placeholder return
}
int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    int result = searchElementInArray(nums, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}