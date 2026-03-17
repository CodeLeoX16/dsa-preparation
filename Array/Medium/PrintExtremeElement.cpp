#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    vector<int>printExtremeElementsAlternately(vector<int>& arr) { 
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int l=0,r=arr.size()-1;
        bool isPiclow=true;
        while(l<=r){
            if(isPiclow){
                ans.push_back(arr[l++]);
                isPiclow=false;
            }else{
                ans.push_back(arr[r--]);
                isPiclow=true;
            }
        }
        return ans;

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
    vector<int> result = printExtremeElementsAlternately(arr);
    cout << "The extreme elements alternately are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

