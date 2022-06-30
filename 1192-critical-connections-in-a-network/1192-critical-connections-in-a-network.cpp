class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<vector<int>> &ans, int u, int parent){
        static int time = 0;
        disc[u] = low[u] = time;
        time++;
        for(int v: adj[u]){
            if(v == parent) continue;
            if(disc[v] == -1){
                dfs(adj, disc, low, ans, v, u);
                if(low[v] > disc[u])
                    ans.push_back({u, v});
            } 
            low[u] = min(low[u], low[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i: connections){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
        }
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            if(disc[i] == -1)
                dfs(adj, disc, low, ans, i, -1);
        }
        return ans;
    }
};