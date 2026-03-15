#include<iostream>
#include<vector>
using namespace std;
bool isEmpty(vector<vector<char>>&board,int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                row=i,col=j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(vector<vector<char>>&board,int row,int col,char num){
     //row
     for(int j=0;j<9;j++){
        if(board[row][j]==num)return false;
     }

     //col
     for(int i=0;i<9;i++){
        if(board[i][col]==num)return false;
     }

     //3*3 board
     int str=row-(row%3);
     int stc=col-(col%3);
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int r=i+str;
            int c=j+stc;
            if(board[r][c]==num)return false;
        }
     }
     return true;
}
bool sudukohelper(vector<vector<char>>&board){
     int row,col;
     if(!isEmpty(board,row,col))return true;
     for(int i=0;i<9;i++){
        char num=i+'1';
        if(isSafe(board,row,col,num)){
            board[row][col]=num;
            if(sudukohelper(board))return true;
            board[row][col]='.';
        }
     }
     return false;
}
void suduko(vector<vector<char>>&board){
    sudukohelper(board);
}
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // Solve Sudoku
    suduko(board);

    // Print solved Sudoku
    cout << "Solved Sudoku:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
