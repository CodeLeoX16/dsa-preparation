#include<iostream>
#include<vector>
using namespace std;
void Reverse(vector<int>&arr,int size,int i){
    if(i<0)return;
    cout<<arr[i]<<" ";
    Reverse(arr,size,i-1);
}
int main(){
    vector<int>arr={1,2,3,4,5};
    int size=arr.size();
    int i=size-1;
    Reverse(arr,size,i);
}