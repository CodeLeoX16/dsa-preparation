#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute force approach is to calculate the left sum and right sum for each index and compare them if they are equal return the index otherwise return -1
int pivotIndex(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n=nums.size();
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<n;i++){
            int leftsum=0;
            int rightsum=0;
            for(int j=0;j<i;j++)leftsum+=nums[j];
            for(int k=i+1;k<n;k++)rightsum+=nums[k];
            if(leftsum==rightsum)return i;
        }
        return -1;

    }
    // optimal approach is to calculate the total sum of the array and then iterate through the array and keep track of the left sum and right sum and compare them if they are equal return the index otherwise return -1
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int leftsum=0;
        for(int i=0;i<n;i++){
            int rightsum=total-leftsum-nums[i];
            if(leftsum==rightsum)return i;
            leftsum+=nums[i];
        }
        return -1;
    }
int main(){
    vector<int>nums={1,7,3,6,5,6};
    cout<<pivotIndex(nums);
}
