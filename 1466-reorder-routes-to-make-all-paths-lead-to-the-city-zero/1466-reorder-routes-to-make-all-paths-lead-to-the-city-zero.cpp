class Solution {
    int dfs(int node, int parent, vector<vector<pair<int,int>>> &adj){
        int count = 0;
        for(auto i: adj[node]){
            if(i.first == parent)
                continue;
            
            count += i.second + dfs(i.first, node, adj);
        }
        return count;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e: connections){
            adj[e[0]].push_back({e[1], 1});
            adj[e[1]].push_back({e[0], 0});
        }
        
        return dfs(0, -1, adj);
    }
};