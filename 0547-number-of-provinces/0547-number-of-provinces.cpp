class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int curr){
        if(vis[curr])
            return;
        vis[curr] = 1;
        for(auto i: adj[curr]){
            dfs(adj, vis, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                ans++;
                
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};