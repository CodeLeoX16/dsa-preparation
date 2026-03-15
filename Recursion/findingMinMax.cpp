#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> findMinMax(vector<int>&arr,int n,int i,int minval,int maxval){
    if(i==n)return{minval,maxval};
    minval=min(arr[i],minval);
    maxval=max(arr[i],maxval);
    return findMinMax(arr,n,i+1,minval,maxval);
    //return{min,max};
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int n=arr.size();
    int i=0;
    int minval=INT_MAX;
    int maxval=INT_MIN;
   vector<int>result= findMinMax(arr,n,i,minval,maxval);
   cout<<"min: "<<result[0]<<" "<<endl;
   cout<<"max: "<<result[1]<<" "<<endl;
}