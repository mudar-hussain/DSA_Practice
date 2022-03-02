// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], int start,  vector<int> &vis, vector<int> &anc){
        vis[start] = 1;
        anc[start] = 1;
        for(auto node: adj[start]){
            if(vis[node] == 0){
                if(dfs(adj, node, vis, anc))
                    return true;
            }else if(anc[node])
                return true;
        }
        anc[start] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V+1, 0);
        vector<int> anc(V+1, 0);
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                if(dfs( adj, i, vis, anc))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends