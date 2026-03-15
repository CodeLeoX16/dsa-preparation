#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// three sumproblem
// logic is to sort the array and then use two pointer approach to find the triplet which sum is zero
vector<vector<int>> threeSum(vector<int>& nums) {
        // Implementation will go here
        vector<vector<int>>ans;
        int n=nums.size();
        // sorting
        sort(nums.begin(),nums.end());
        // two pointer
        for(int i=0;i<n;i++){
            if(i>0&& nums[i]==nums[i-1])continue;
            // initialize j and i
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k&& nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                }
                
               else if(sum<0)j++;
                else k--;
            }
        }
        return ans;
    }
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threeSum(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}