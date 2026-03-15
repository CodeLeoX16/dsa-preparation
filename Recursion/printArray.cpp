#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int>&arr,int size,int i){
    if(i>=size){
        
        return;
    }
    cout<<arr[i]<<" ";
    printArray(arr,size,i+1);
}
int main(){
    //int size=5;
    vector<int>arr={1,2,3,4,5};
    int size=arr.size();
    int i=0;
    printArray(arr,size,i);
}