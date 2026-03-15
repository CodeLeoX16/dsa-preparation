#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void QuickSort(vector<int>&arr,int st,int end){
    if (st >= end) return;
    int i=st-1;
    int j=st;
    int pivot=end;
    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);   
        }
        j++;
    }
    i++;
    swap(arr[i],arr[pivot]);
    QuickSort(arr,st,i-1);
    QuickSort(arr,i+1,end);
    
}
int main(){
    vector<int>arr={4,3,6,2,7,1};
    int st=0;
    int end=arr.size()-1;
    QuickSort(arr,st,end);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}