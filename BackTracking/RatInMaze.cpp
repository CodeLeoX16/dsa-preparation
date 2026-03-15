#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<char>>&board,vector<vector<bool>>&visited,int row,int col,int newR,int newC){
     if( (newR>=0 && newR<row)&& (newC>=0 && newC<col)&&board[newR][newC]!='X'&&!visited[newR][newC]){
        return true;
     }
     return false;
}
void solve(vector<vector<char>>&board,vector<vector<bool>>&visited,string path,vector<string>&ans,int row,int col,int srcR,int srcC,int destR,int destC){
    if(srcR==destR && srcC==destC ){
        ans.push_back(path);
        return;
    }
    //up
    int newR=srcR-1;
    int newC=srcC;
    
        if(isSafe(board,visited,row,col,newR,newC)){
            visited[newR][newC]=true;
            solve(board,visited,path+'U',ans,row,col,newR,newC,destR,destC);
            visited[newR][newC]=false;;

        }
    

    //down
    newR=srcR+1;
    newC=srcC;
   
        if(isSafe(board,visited,row,col,newR,newC)){
            visited[newR][newC]=true;
            solve(board,visited,path+'D',ans,row,col,newR,newC,destR,destC);
            visited[newR][newC]=false;;

        }
    
    //left
    newR=srcR;
    newC=srcC-1;
    
        if(isSafe(board,visited,row,col,newR,newC)){
            visited[newR][newC]=true;
            solve(board,visited,path+'L',ans,row,col,newR,newC,destR,destC);
            visited[newR][newC]=false;;

        }
    

    //right
    newR=srcR;
    newC=srcC+1;
    
        if(isSafe(board,visited,row,col,newR,newC)){
            visited[newR][newC]=true;
            solve(board,visited,path+'R',ans,row,col,newR,newC,destR,destC);
            visited[newR][newC]=false;;

        }
    
}
vector<string>ratinMaze(vector<vector<char>>&board){
    int row=board.size();
    int col=board[0].size();
    int srcR=0;
    int srcC=0;
    int destR=row-1;
    int destC=col-1;
    string path="";
    vector<string>ans;
    vector<vector<bool>>visited(row,vector<bool>(col,false));
    visited[0][0] = true;
    solve(board,visited,path,ans,row,col,srcR,srcC,destR,destC);
    return ans;

}
int main(){
    vector<vector<char>> board = {
    {'.', 'X', '.', '.'},
    {'.', '.', '.', 'X'},
    {'X', '.', '.', '.'},
    {'.', '.', 'X', '.'}
};    
    vector<string> ans = ratinMaze(board);

    for (auto &s : ans) {
        cout << s << endl;
    }

    return 0;
   
    

}