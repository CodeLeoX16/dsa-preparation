#include<iostream>
#include<vector>
using namespace std;
int largetselement(vector<int>&arr){
    int n=arr.size();
    int lar=arr[0];
    for(int i=1;i<n;i++){
        if(lar<arr[i])lar=arr[i];
    }
    return lar;

}
int main(){
    vector<int>arr={3,4,56,7,5,3};
    cout<<largetselement(arr);
}
