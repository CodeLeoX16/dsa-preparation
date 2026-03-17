#include<iostream>
#include<vector>
using namespace std;
    double findAverage(const vector<int>& arr) {
        // Implement logic to find the average
        double n=arr.size();
        double sum=0;
        for(int num:arr){
            sum+=num;
        }
        double ans=(sum*1.0)/n;
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

    double average = findAverage(arr);
    cout << "The average of the array is: " << average << endl;

    return 0;
}
