 
#include<iostream>
#include<vector>
using namespace std;

 
 pair<int, int> sumPositiveNegative(const vector<int>& arr) {
        // Implement logic to calculate sums of positive and negative elements
        int n=arr.size();
        int Psum=0,Nsum=0;
        vector<int>result=arr;

        for(int i=0;i<n;i++){
            if(result[i]>=0){
                Psum+=result[i];
            }else{
                Nsum+=result[i];
            }
        }
        return{Psum,Nsum};
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
    pair<int, int> sums = sumPositiveNegative(arr);
    cout << "Sum of positive elements: " << sums.first << endl;
    cout << "Sum of negative elements: " << sums.second << endl;
    return 0;
}