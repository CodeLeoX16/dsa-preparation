#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int>&stalls,int c,int sol){
    int n=stalls.size();
    int lastlength=stalls[0];
    int cow=1;
    for(int i=1;i<n;i++){
        if(stalls[i]-lastlength>=sol){
            cow++;
            lastlength=stalls[i];
            if(cow==c)return true;
        }
    }
    return false;
}
int minimumdistance(vector<int>&stalls,int c){
    sort(stalls.begin(),stalls.end());
    int st=0;
    int end=stalls.back()-stalls.front();
    int ans=-1;
    if(stalls.size()<c)return -1;
    while(st<=end){
        int mid=(st+end)/2;
        if(ispossible(stalls,c,mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int main() {

    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;

    int result = minimumdistance(stalls, cows);

    cout << "Largest minimum distance = " << result << endl;

    return 0;
}