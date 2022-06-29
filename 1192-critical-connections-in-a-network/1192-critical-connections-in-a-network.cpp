class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<vector<int>> &bridges, vector<int> &disc, vector<int> &low, vector<int> &parent, int src){
        static int time = 0;
        disc[src] = low[src] = time;
        time++;
        for(int i: adj[src]){
            if(i == parent[src]) continue;
            if(disc[i] == -1){
                parent[i] = src;
                dfs(adj, bridges, disc, low, parent, i);
                low[src] = min(low[src], low[i]);
                if(low[i] > disc[src])
                    bridges.push_back({src, i});
            }else
                low[src] = min(low[src], disc[i]);
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
        vector<vector<int>> bridges;
        for(int i = 0; i<n; i++){
            if(disc[i] == -1)
                dfs(adj, bridges, disc, low, parent, i);
        }
        return bridges;   
    }
};