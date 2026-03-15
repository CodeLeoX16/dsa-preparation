#include<iostream>
using namespace std;
void ReverseCharArray(char *arr,int n){
    int i=0,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void print(char *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
   char arr[5]={'h', 'e', 'l', 'l', 'o'};
   int n=5;
   ReverseCharArray(arr,n);
   print(arr,n); 

}