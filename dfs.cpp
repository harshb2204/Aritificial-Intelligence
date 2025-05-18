#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& result) {
        vis[node] = 1;
        result.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<int> vis(V, 0);

        // DFS can start from any node; here, we start from node 0
        dfs(0, adj, vis, result);
        return result;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // comment this line if the graph is directed
}

void printAns(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vector<int> adj[5];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);
    cout << endl;

    return 0;
}
