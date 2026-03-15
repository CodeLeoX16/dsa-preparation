#include<iostream>
#include<vector>
using namespace std;
int pivot(vector<int>&arr){
    int n=arr.size();
    int st=0,end=n-1;
    if(arr[st]<=arr[end]){
        return end;
    }
    while(st<=end){
        int mid=(st+end)/2;
        if(mid<n-1&&arr[mid]>arr[mid+1] ){
            return mid;
        }
        if(arr[mid] >= arr[st]) st = mid + 1;  // left part sorted → pivot is on right arr = {6, 7, 1, 2, 3, 4, 5};
        else end = mid - 1;                     // pivot on left

    }
    return -1;
}
int BS(int st,int end,vector<int>&arr,int target){
    while(st<=end){
    int mid=(st+end)/2;
    if(arr[mid]==target)return mid;
    if(arr[mid]>target)end=mid-1;
    else st=mid+1;
    }
    return -1;
}
int main(){
    vector<int>arr={6,7,8,9,1,2,3,4};
    int target=1;
    int idx=pivot(arr);
    int n=arr.size();
    if(target>=arr[0] && target<=arr[idx]){
        int ans=BS(0,idx,arr,target);
        cout<<ans;
    }else{
        int ans=BS(idx+1,n-1,arr,target);
        cout<<ans;
    }
}