#include<iostream>
#include<vector>
using namespace std;
void MergeTwosortedArray(vector<int>&arr1,vector<int>&arr2,int n,int m,vector<int>&output){
    
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            output.push_back(arr1[i]);
            i++;
        }else{
            output.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        output.push_back(arr1[i]);
        i++;

    }
    while(j<m){
        output.push_back(arr2[j]);
        j++;
    }

}
int main(){
    vector<int>arr1={1,2,3,4};
    vector<int>arr2={5,6,7,8};
    int n=arr1.size();
    int m=arr2.size();
    vector<int>output;
    MergeTwosortedArray(arr1,arr2,n,m,output);
    for(int i=0;i<n+m;i++){
        cout<<output[i]<<" ";
    }
}