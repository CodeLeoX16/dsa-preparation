#include<iostream>
#include<vector>
using namespace std;
void combinationHelper(vector<int>&arr,int target,vector<int>&v,vector<vector<int>>&ans,int i){
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0)return;
    for(int j=i;j<arr.size();j++){
        v.push_back(arr[j]);
        combinationHelper(arr,target-arr[j],v,ans,i);
        v.pop_back();
    }
}

vector<vector<int>>Combination(vector<int>&arr,int target){
    
    
    vector<vector<int>>ans;
    vector<int>v;
    combinationHelper(arr,target,v,ans,0);
    return ans;
}
int main(){
    vector<int>arr={2,3,4,7};
    int target=7;
    vector<vector<int>>ans=Combination(arr,target);
    for(auto it:ans){
        for(auto n:it){
            cout<<n<<" ";
        }
        cout<<endl;
    }

}