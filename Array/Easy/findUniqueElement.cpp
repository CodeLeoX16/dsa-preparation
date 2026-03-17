#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findUniqueElement(vector<int>& nums){
        int n=nums.size();
        //int count=0;
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        for(int num:nums){
            if(freq[num]==1)
            return num;
        }
        return -1;
    }
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int uniqueElement = findUniqueElement(nums);
    if (uniqueElement != -1) {
        cout << "The unique element in the array is: " << uniqueElement << endl;
    } else {
        cout << "No unique element found in the array." << endl;
    }

    return 0;
}
