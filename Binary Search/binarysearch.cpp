#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int>arr,int target){
    int n=arr.size();
    int st=0,end=n-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(arr[mid]==target)return mid;
        if(arr[mid]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return -1;

}
int main(){
    vector<int>arr={1,2,3,4,5,6,8};
    int target=6;
    cout<<BinarySearch(arr,target);
}