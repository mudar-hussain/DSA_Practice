class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int s){
        for(int i: adj[s]){
            if(vis[i] == false){
                vis[i] = true;
                dfs(adj, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        vector<vector<int>> adj(m+1);
        vector<int> vis(m+1);
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<m; j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0; i<m; i++){
            if(vis[i] == false){
                vis[i] = true;
                ans++;
                dfs(adj, vis, i);
            } 
        }
        return ans;
    }
};