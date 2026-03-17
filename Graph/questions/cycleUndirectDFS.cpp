#include<iostream>
#include<vector>
#include<unordered_map>
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

    bool cycledtection(int src,
                       unordered_map<int, vector<int>>& adjlist,
                       int parent,
                       unordered_map<int, bool>& vis) {

        vis[src] = true;

        for (auto neigh : adjlist[src]) {
            if (!vis[neigh]) {
                if (cycledtection(neigh, adjlist, src, vis))
                    return true;     
            }
            else if (neigh != parent) {
                return true; // cycle found
            }
        }
        return false;
    }

    bool iscycleDFS(int V,
                    unordered_map<int, vector<int>>& adjlist) {

        unordered_map<int, bool> vis;

        for (int src = 0; src < V; src++) {
            if (!vis[src]) {
                if (cycledtection(src, adjlist, -1, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        returnAdjlist(edges, adjlist);

        return iscycleDFS(V, adjlist);
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