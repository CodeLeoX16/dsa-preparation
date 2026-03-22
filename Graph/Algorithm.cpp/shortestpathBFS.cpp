#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
class Graph{
    public:
    unordered_map<int,vector<int>>adjlist;
    void addEdge(int u,int v,bool directed){
        if(directed){
            adjlist[u].push_back(v);
        }else{
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }
   void shortestpathBFS(int src,int dest){
       queue<int>q;
       unordered_map<int,bool>vis;
       unordered_map<int,int>parent;
       //initial state maintain
       q.push(src);
       vis[src]=true;
       parent[src]=-1;
       while(!q.empty()){
           int front=q.front();
           
           q.pop();
           if(front == dest) break;
           for(auto neigh:adjlist[front]){
               if(!vis[neigh]){
                   q.push(neigh);
                   parent[neigh]=front;
                   vis[neigh]=true;
               }
           }
       }
       // check if reachable
        if(!vis[dest]){
            cout << "No path exists" << endl;
            return;
        }
       
       //noew path finding
       vector<int>path;
       int node=dest;
       while(node!=-1){
           path.push_back(node);
           node=parent[node];
       }
       reverse(path.begin(),path.end());
       cout<<"printitng the path ";
       for(int i:path){
           cout<<i<<"->";
       }
       cout<<endl;
   }
};
int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(3,5,0);
    vector<int>parentarray;
    unordered_map<int,bool>vis;
   g.shortestpathBFS(0,3);
    
    
    
}
