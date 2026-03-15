#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int secpondlaregt(vector<int>&arr){
    int largets=INT_MIN;
    int second=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>largets){
            second=largets;
            largets=arr[i];
        }
        if(arr[i]<largets&&arr[i]>second){
            second=arr[i];
        }
    }
    return (second==INT_MIN)?-1:second;
}
int main(){
    vector<int>arr={1,3,2,4,23,12,14,12,45};
    cout<<secpondlaregt(arr);
}