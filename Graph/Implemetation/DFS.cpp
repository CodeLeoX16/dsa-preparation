#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
    void DFShelper(int src,unordered_map<int,bool>&visited){
        cout<<src<<" ";
        visited[src]=true;
        for(auto neigh:adjast[src]){
            if(!visited[neigh]){
                DFShelper(neigh,visited);
            }
        }
    }
    void DFS(int src,int n){
        unordered_map<int,bool>visited;
        for(int src=0;src<n;src++){
            if(!visited[src]){
                DFShelper(src,visited);
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
    g.DFS(0,6);
    
    
    
}