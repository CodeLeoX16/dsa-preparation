#include<iostream>
#include<vector>
using namespace std;

int LastOccurenceOfEle(vector<int>&arr,int key){
    int st=0,end=arr.size()-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==key){
            ans=mid;
            st=mid+1;

        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr={1,2,3,3,3,3,4,5};
    int key=3;
    cout<<"Last Occurence of the given element is "<<LastOccurenceOfEle(arr,key);
}