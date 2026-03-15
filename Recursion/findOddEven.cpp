#include <iostream>
#include <vector>
using namespace std;
void findEvenOdd(vector<int>&arr,int n,int i){
    if(i==n)return;
    if(arr[i]%2==0){
        cout<<arr[i]<<"is an even number"<<endl;
    }
    else {
        cout<<arr[i]<<"is an odd number"<<endl;
    }
   findEvenOdd(arr,n,i+1);
}
int main(){
    vector<int>arr={11,12,14,16};
    int n=arr.size();
    int i=0;
    findEvenOdd(arr,n,i);
}