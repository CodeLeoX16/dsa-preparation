#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int j=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
}

    // optimal approach is to use the set approach and keep track of the unique elements and return the length of the unique elements
    int removeDuplicates(vector<int>& nums) {
        // Implement logic here
        if(nums.size()==1)return 1;
        set<int>s;
        for(int num:nums)s.insert(num);
        return s.size();
    }
int main(){
    vector<int>nums={1,1,2,2,3,4,5,5};
    cout<<removeDuplicates(nums);
}