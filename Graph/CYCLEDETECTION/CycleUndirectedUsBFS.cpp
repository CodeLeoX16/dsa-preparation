#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:

    void returnAdjlist(vector<vector<int>>& edges,
                       unordered_map<int, vector<int>>& adjlist) {
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }

    bool isCyclePresent(int src,
                        unordered_map<int, vector<int>>& adjlist,
                        unordered_map<int, bool>& vis,
                        unordered_map<int, int>& parent) {

        queue<int> q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int currnode = q.front();
            q.pop();

            for (auto neigh : adjlist[currnode]) {
                if (!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                    parent[neigh] = currnode;
                }
                else if (neigh != parent[currnode]) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adjlist;
        returnAdjlist(edges, adjlist);

        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;

        for (int src = 0; src < V; src++) {
            if (!vis[src]) {
                if (isCyclePresent(src, adjlist, vis, parent)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    if (obj.isCycle(V, edges)) {
        cout << "Cycle Present\n";
    } else {
        cout << "No Cycle\n";
    }

    return 0;
}