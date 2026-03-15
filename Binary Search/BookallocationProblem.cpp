#include <iostream>
#include <vector>
using namespace std;

/*
    Function to calculate total number of pages
    This gives the upper bound for binary search
*/
int totalpages(vector<int>& arr) {
    int sum = 0;

    // Add pages of all books
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

/*
    Function to check if it is possible to
    allocate books to 'm' students such that
    no student gets more than 'sol' pages
*/
bool ispossible(vector<int>& arr, int m, int sol) {
    int pagesum = 0;   // current pages allocated to a student
    int c = 1;         // count of students used

    for (int i = 0; i < arr.size(); i++) {

        // If a single book has more pages than sol,
        // allocation is impossible
        if (arr[i] > sol)
            return false;

        // If adding current book exceeds sol,
        // allocate book to next student
        if (pagesum + arr[i] > sol) {
            c++;                // move to next student
            pagesum = arr[i];  // start new page sum

            // If students exceed m, allocation fails
            if (c > m)
                return false;
        } 
        // Otherwise, add book to current student
        else {
            pagesum += arr[i];
        }
    }

    // Allocation possible within m students
    return true;
}

/*
    Function to find minimum possible maximum pages
    using Binary Search on the answer
*/
int minpage(vector<int>& arr, int m) {
    int st = 0;                  // minimum possible pages
    int ans = -1;

    // If students are more than books, allocation impossible
    if (arr.size() < m)
        return -1;

    int end = totalpages(arr);   // maximum possible pages

    // Binary Search on answer space
    while (st <= end) {
        int mid = (st + end) / 2;   // mid represents current solution

        // Check if current mid is a valid allocation
        if (ispossible(arr, m, mid)) {
            ans = mid;        // store possible answer
            end = mid - 1;    // try to minimize pages
        } 
        // If not possible, increase pages
        else {
            st = mid + 1;
        }
    }

    // Minimum maximum pages
    return ans;
}

/*
    Main function to test Book Allocation
*/
int main() {
    vector<int> arr = {12, 34, 67, 90}; // pages in each book
    int m = 2;                          // number of students

    cout << "Minimum pages = " << minpage(arr, m) << endl;
    return 0;
}
