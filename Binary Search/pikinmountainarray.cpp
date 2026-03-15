#include<iostream>
#include<vector>
using namespace std;
int pikInMountainArray(vector<int>&arr){
    int pik=-1;
    int st=0,end=arr.size()-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(arr[mid]>arr[mid+1]){
            pik=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return pik;
}
int main(){
    vector<int>arr={5,6,7,8,1,2,3,4};
    cout<<pikInMountainArray(arr);
}