#include<iostream>     // For input and output
#include<vector>       // For vector container
#include<algorithm>    // For max_element
using namespace std;

/*
    This function checks whether it is possible
    to cook at least 'p' pratas using 'c' cooks
    within 'sol' time.
*/
bool ispossible(vector<int>& ranks, int p, int c, int sol){

    int currpr = 0;   // Total pratas cooked so far

    // Loop through each cook
    for(int i = 0; i < c; i++){

        int time = 0;        // Time spent by current cook
        int R = ranks[i];    // Rank of current cook
        int j = 1;           // Prata count for this cook

        /*
            Time taken by a cook of rank R:
            1st prata  -> R * 1
            2nd prata  -> R * 2
            3rd prata  -> R * 3
            ...
        */
        while(time + j * R <= sol){

            time += j * R;   // Add time for j-th prata
            j++;             // Move to next prata
            currpr++;        // One prata cooked

            // If required pratas are cooked
            if(currpr >= p)
                return true;
        }
    }

    // If total pratas cooked are less than required
    return false;
}

/*
    This function finds the minimum time required
    to cook 'p' pratas using 'c' cooks.
*/
int totaltime(vector<int>& ranks, int p, int c){

    int st = 0;   // Minimum possible time

    // Find maximum rank (slowest cook)
    int h = *max_element(ranks.begin(), ranks.end());

    /*
        Worst-case scenario:
        Only the slowest cook (rank h) cooks all pratas

        Total time:
        h * (1 + 2 + 3 + ... + p)
        = h * (p * (p + 1)) / 2
    */
    int end = h * (p * (p + 1)) / 2;

    int ans = 0;  // Stores minimum time required

    // Binary Search on time
    while(st <= end){

        int mid = st + (end - st) / 2;

        // Check if cooking is possible in 'mid' time
        if(ispossible(ranks, p, c, mid)){
            ans = mid;        // Store possible answer
            end = mid - 1;    // Try to find smaller time
        }
        else{
            st = mid + 1;     // Increase time
        }
    }

    return ans;
}

int main(){

    // Ranks of cooks
    vector<int> ranks = {1, 2, 3, 4};

    int p = 10;  // Number of pratas to cook
    int c = 4;   // Number of cooks

    // Print minimum time required
    cout << totaltime(ranks, p, c);

    return 0;
}
