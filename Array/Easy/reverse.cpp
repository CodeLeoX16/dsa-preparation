#include<iostream>
#include<vector>
using namespace std;

    vector<int> reverseArray(const vector<int>& arr) {
        // Implement logic to reverse the array
        vector<int>result=arr;
        int n=result.size();
        int i=0;
        int j=n-1;
        while(i<j){
            swap(result[i],result[j]);
            i++;
            j--;
        }
        return result;
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

    vector<int> reversedArray = reverseArray(arr);
    cout << "The reversed array is: ";
    for (int num : reversedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}