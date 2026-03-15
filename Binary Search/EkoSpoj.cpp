#include<iostream>      // For input-output operations
#include<vector>        // For using vector container
#include<numeric>       // For accumulate (not used now, but kept)
#include<algorithm>     // For max_element
using namespace std;

/*
    This function checks whether it is possible
    to collect at least 'm' units of wood if the
    cutter is set at height 'sol'
*/
bool ispossible(vector<int>& trees, int m, int sol){
    int wood = 0;   // Stores total collected wood

    // Traverse through each tree
    for(int i = 0; i < trees.size(); i++){
        
        // Only trees taller than cutter height contribute wood
        if(trees[i] > sol){
            wood += trees[i] - sol;  // Collect excess wood
            
            // If required wood is collected, return true
            if(wood >= m)
                return true;
        }
    }

    // If total wood is less than required
    return false;
}

/*
    This function finds the maximum possible height
    at which the cutter can be placed so that
    at least 'm' wood is collected
*/
int cutterplace(vector<int>& trees, int m){

    int st = 0;   // Minimum possible cutter height
    int end = *max_element(trees.begin(), trees.end()); 
                 // Maximum possible cutter height (tallest tree)

    int ans = -1; // Stores the final answer

    // Binary Search on Answer
    while(st <= end){

        // Calculate mid safely to avoid overflow
        int mid = st + (end - st) / 2;

        // Check if cutting at height 'mid' is possible
        if(ispossible(trees, m, mid)){
            ans = mid;        // Store valid height
            st = mid + 1;     // Try to find a higher possible height
        }
        else{
            end = mid - 1;    // Reduce cutter height
        }
    }

    return ans; // Return maximum valid cutter height
}

int main(){
    // Heights of trees
    vector<int> trees = {20, 15, 10, 17};

    // Required amount of wood
    int m = 7;

    // Print the maximum cutter height
    cout << cutterplace(trees, m);

    return 0;
}
