#include<iostream>
#include<vector>
using namespace std;

int findFirstUnsortedIndex(const vector<int>& arr) {
        // Implement logic to find first unsorted index
        //int n=arr.size();
        vector<int>result=arr;
        for(int i=1;i<result.size();i++){
            if(result[i-1]>result[i]) return i-1;
        }
        return -1;
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

    int unsortedIndex = findFirstUnsortedIndex(arr);
    if (unsortedIndex != -1) {
        cout << "The first unsorted index is: " << unsortedIndex << endl;
    } else {
        cout << "The array is already sorted." << endl;
    }

    return 0;
}