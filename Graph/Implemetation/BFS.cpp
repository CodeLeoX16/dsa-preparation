// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph{
    public:
    unordered_map<int,vector<int>>adjast;
    void addEdge(int u ,int v,bool directed){
        if(directed){
            //directed edge
            adjast[u].push_back(v);
            
        }else{
            // undirected edge
            adjast[v].push_back(u);
            adjast[u].push_back(v);
        }
    }
    void BFS(int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cout<<front<<" ";
            for(auto neigh:adjast[front]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh]=true;
                }
            }
        }

    }

};
int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.BFS(0);
    
    
    
}