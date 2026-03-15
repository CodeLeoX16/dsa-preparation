#include<iostream>
#include<vector>
using namespace std;
int SqurerootOfEle(int num){
    int ans=0;
    int st=0,end=num/2;
    if(num==0||num==1)return num;
    while(st<=end){
        long long mid=(st+end)/2;
        long long product=mid*mid;
        if(product==num){
            ans=mid;
            break;
        }
        if(product>num){
            end=mid-1;

        }
        else{
            ans=mid;
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    int num=626;
    cout<<"the squreroot of the element is "<<SqurerootOfEle(num);
}