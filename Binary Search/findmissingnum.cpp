#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int missingnum(vector<int>&nums){
    sort(nums.begin(),nums.end());
    int missNum=-1;
    int st=0,end=nums.size()-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(nums[mid]==mid){
            st=mid+1;
        }else{
            end=mid-1;
        }

    }
    return st;
}
int main(){
    vector<int>nums={0,1,2,3,5,6,7};
    cout<<missingnum(nums);
}
