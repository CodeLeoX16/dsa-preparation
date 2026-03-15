#include<iostream>
#include<vector>
using namespace std;
int pivot(vector<int>&arr){
    int st=0,end=arr.size()-1;
    int n=arr.size();
    if(arr[st]<=arr[end])return end;
    while(st<=end){
        int mid=(st+end)/2;
        if(mid<n-1&&arr[mid]>arr[mid+1]){
            return mid;

        }
        if(arr[mid] >= arr[st]) st = mid + 1;  // left part sorted → pivot is on right
        else end = mid - 1;                     // pivot on left

    }
    return -1;
}
int main(){
    vector<int>arr={4, 5, 6, 7, 1, 2, 3};
    cout<<pivot(arr);
}