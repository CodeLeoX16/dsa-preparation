#include<iostream>
#include<vector>
using namespace std;
vector<int> shiftRight( vector<int>& arr) {
        int n=arr.size();
        int last=arr[n-1];
        for(int i=n-1;i>=0;i--){
            arr[i]=arr[i-1];
            if(i==0)arr[0]=last;
        }
        return arr;
    }
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> shiftedArray = shiftRight(arr);
    cout << "The array after shifting right by one place is: ";
    for (int num : shiftedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}