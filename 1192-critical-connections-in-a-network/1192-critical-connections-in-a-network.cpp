class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &ans, int u){
        static int time = 0;
        disc[u] = low[u] = time;
        time++;
        for(int v: adj[u]){
            if(v == parent[u]) continue;
            if(disc[v] == -1){
                parent[v] = u;
                dfs(adj, disc, low, parent, ans, v);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u])
                    ans.push_back({u, v});
            }else 
                low[u] = min(low[u], disc[v]);
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
        vector<int> parent(n, -1);
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            if(disc[i] == -1)
                dfs(adj, disc, low, parent, ans, i);
        }
        return ans;
    }
};