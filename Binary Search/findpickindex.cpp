#include<iostream>
#include<vector>
using namespace std;
int pickindex(vector<int>&arr){
    int n=arr.size();
    if(arr.size()==0)return 0;
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2])return n-1;
    int st=1,end=n-2;
    while(st<=end){
        int mid=(st+end)/2;
        if(arr[mid]>arr[mid+1]&& arr[mid]>arr[mid-1])return mid;
        else if(arr[mid]<arr[mid+1]){
            st=mid+1;
        }
        else end=mid-1;
    }
    return -1;
}
int main(){
    vector<int>arr={1,2,1,3,5,6,4};
    cout<<pickindex(arr);
}