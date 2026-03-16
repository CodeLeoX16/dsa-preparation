// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
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
    // if waited to print the graph then we can use the adjast list to print the graph
    unordered_map<int,vector<pair<int,int>>>adjastwt;
    void addEdge(int u,int v,int wt,bool directed){
        if(directed){
            // directed edge
            adjastwt[u].push_back(make_pair(v,wt));
            
        }else{
            // undirected edge
            adjastwt[v].push_back(make_pair(u,wt));
            adjastwt[u].push_back(make_pair(v,wt));
        }
    }
    void Print(int n){
        for(int i=0;i<=n;i++){
            cout<<i<<" :";
            cout<<"{";
            for(auto j:adjast[i]){
                cout<<j;
            }
            cout<<"}"<<endl;
        }
    }
};
int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.Print(5);
    
    
    
}