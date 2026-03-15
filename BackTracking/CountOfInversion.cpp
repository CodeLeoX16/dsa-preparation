#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&arr,int st,int end,int mid){
    int i=st;
    int j=mid+1;
    vector<int>temp;
    int inv_count=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);

        }else{
            temp.push_back(arr[j++]);
            inv_count+=(mid-st+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=mid){
        temp.push_back(arr[j++]);
    }
    for(int i=st;i<=end;i++){
        arr[i]=temp[i-st];

    }
    return inv_count;
}

int mergeSort(vector<int>&arr,int st,int end){
    int inv_count=0;
    
    if(st<end){
        int mid=(st+end)/2;
        inv_count+=mergeSort(arr,st,mid);
        inv_count+=mergeSort(arr,mid+1,end);
        inv_count+=merge(arr,st,end,mid);

    }
    return inv_count;
}

int mergeSortcount(vector<int>&arr){
    
    return mergeSort(arr,0,arr.size()-1);
}
int main(){
    vector<int>  arr={8,4,2,1};
    cout<<mergeSortcount(arr);
}