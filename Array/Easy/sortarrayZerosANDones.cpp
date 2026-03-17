#include<iostream>
#include<vector>
using namespace std;

    vector<int> sortArray(vector<int>& nums) {
        // Implement the function here.
        vector<int>result=nums;
        int n=result.size();
        int totalZero=0;//totalone=0;
        for(int i=0;i<n;i++){
            if(result[i]==0)totalZero++;
           // if(result[i]==1)totalone++;

        }
        fill(result.begin(),result.begin()+totalZero,0);
        fill(result.begin()+totalZero,result.end(),1);
        return result;

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

    vector<int> sortedArray = sortArray(nums);
    cout << "The sorted array is: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}