#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maximumsum(vector<int>&arr){
    int n=arr.size();
    int mxsum=INT_MIN;
    int currsum=0;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum>mxsum){
            mxsum=currsum;
        }
        if(currsum<0)currsum=0;
    }
    return mxsum;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,-7,-8};
    cout<<maximumsum(arr);
}