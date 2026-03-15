#include<iostream>
#include<vector>
using namespace std;
void findElement(vector<int>&arr,int size,int i ,int target){
    if(i>=size){
       return;
    }
    if(arr[i]==target){
        cout<<i<<" ";
    }
    findElement(arr,size,i+1,target);
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int size=arr.size();
    int i=0;
    int target=4;
    findElement(arr,size,i,target);
}