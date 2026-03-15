// . Q . .
// . . . Q
// Q . . .
// . . Q .

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 bool isSafe(vector<string>&board,int row,int col,int n){
    int i=0;
    while(i<row){
        if(board[i][col]=='Q')return false;
        i++;

    }

    // leftdiaonal
    i=row-1;
    int j=col-1;
    while(i>=0&& j>=0){
        if(board[i][j]=='Q')return false;
        i--;
        j--;

    }

    //right diagonal
    i=row-1;
    j=col+1;
    while(i>=0 && j<n){
        if(board[i][j]=='Q')return false;
        i--;
        j++;
    }
    return true;

      
 }

void solve(vector<string>&board,vector<vector<string>>&ans,int row ,int n){
    if(row==n){
        ans.push_back(board);
        return;

    }
    int col=0;
    while(col<n){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(board,ans,row+1,n);
            board[row][col]='.';
            
        }
        col++;
        
    }
    
          
 }
 vector<vector<string>>Nqueen(int n){ 
    vector<string>board(n,string(n,'.'));
    vector<vector<string>>ans;
    solve(board,ans,0,n);
    return ans;
 }

 int main() {
    int n = 4;
    vector<vector<string>> ans = Nqueen(n);

    for (auto &solution : ans) {
        for (auto &row : solution) {
            cout << row << endl;
        }
        cout << "-----" << endl;
    }

    return 0;
}

