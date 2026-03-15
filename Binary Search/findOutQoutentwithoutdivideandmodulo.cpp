#include<iostream>
#include<climits>
#include <cstdlib>
using namespace std;
int quosent(int divisor,int dividend){
    if(divisor==0)return INT_MAX;
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    long long a = abs((long long)divisor);
    long long b = abs((long long)dividend);
    int st=0,end=b;
    int ans=0;
    while(st<=end){
        int mid=(st+end)/2;
        long long product=mid*divisor;
        if(product==b){
            ans=mid;
            break;
        }
        if(product>b){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    if((divisor>0 && dividend<0 )||(divisor<0 && dividend>0)){
        return ans=0-ans;
    }else{
        return ans;
    }


    
}
int main(){
    int divisor=10;
    int dividend=80;
    cout<<quosent(divisor,dividend);
}