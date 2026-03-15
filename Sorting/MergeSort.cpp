#include<iostream>
#include<vector>
using namespace std;
void Merge(vector<int>&arr,int st,int end,int mid){
    int leftLen=mid-st+1;
    int rightLen=end-mid;
    int *arr1=new int[leftLen];
    int *arr2=new int [rightLen];
    int mainArrIdx=st;
    for(int i=0;i<leftLen;i++){
        arr1[i]=arr[mainArrIdx++];
    }
    mainArrIdx=mid+1;
    for(int j=0;j<rightLen;j++){
        arr2[j]=arr[mainArrIdx++];
    }
    int i=0;
    int j=0;
    mainArrIdx=st;
    while(i<leftLen && j<rightLen){
        if(arr1[i]<arr2[j]){
            arr[mainArrIdx]=arr1[i];
            mainArrIdx++;
            i++;
        }else{
            arr[mainArrIdx]=arr2[j];
            mainArrIdx++;
            j++;
        }

    }
    while(i<leftLen){
        arr[mainArrIdx]=arr1[i];
        mainArrIdx++;
        i++;
    }
    while(j<rightLen){
        arr[mainArrIdx]=arr2[j];
        mainArrIdx++;
        j++;
    }
    delete []arr1;
    delete [] arr2;
}

void MergeSort(vector<int>&arr,int st,int end){
    if(st>=end)return;
    int mid=(st+end)/2;
    MergeSort(arr,st,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,st,end,mid);
}
int main(){
    vector<int>arr={6,5,3,4,2,1};
    int st=0;
    int end=arr.size()-1;
    MergeSort(arr,st,end);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    
    }
}