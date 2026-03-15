#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int st,int end,int mid){
    int total=end-st+1;
    int gap=(total%2 )+(total/2);
    while(gap>0){
        int i=st,j=st+gap;
        while(j<=end){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
                
            }
            i++;
            j++;
        }
        // gap=gap<=1?0:(gap%2)+(gap/2);
        if (gap == 1) gap = 0;
        else gap = (gap / 2) + (gap % 2);
    }
    
}
void mergeSort(vector<int>&arr,int st,int end){
    if(st>=end)return;
    int mid=(st+end)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,end,mid);

}
int main(){
    vector<int>arr={4,3,5,2,6,9,8,1,7};
    int n=arr.size();
    int st=0;
    int end=n-1;
    mergeSort(arr,st,end);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}