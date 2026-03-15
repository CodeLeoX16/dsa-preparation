#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Search2dMatrix(vector<vector<int>>&arr,int target){
    int row=arr.size();
    int col=arr[0].size();
    int total=row*col;
    int st=0,end=total-1;
    while(st<=end){
        int mid=(st+end)/2;
        int rowidx=mid/col;
        int colidx=mid%col;
        if(arr[rowidx][colidx]==target){
            return true;
        }
        if(arr[rowidx][colidx]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>>arr= {{1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};
    int target=11;
    cout<<Search2dMatrix(arr,target);
}