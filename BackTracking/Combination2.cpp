#include<iostream>
#include<vector>
using namespace std;
void CombinationHelper(vector<int>&arr,int target,vector<int>&v,vector<vector<int>>&ans,int i){
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0)return;
    for(int j=i;j<arr.size();j++){
        if(j>i && arr[j]==arr[j-1])continue;
        v.push_back(arr[j]);
        CombinationHelper(arr,target-arr[j],v,ans,i+1);
        v.pop_back();
    }
}
vector<vector<int>>combination(vector<int>&arr,int target){
    vector<int>v;
    vector<vector<int>>ans;
    CombinationHelper(arr,target,v,ans,0);
    return ans;
}
int main(){
    vector<int>arr={2,3,4,7};
    int target=7;
    vector<vector<int>>ans=combination(arr,target);
    for(auto it:ans){
        for(auto n:it){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}