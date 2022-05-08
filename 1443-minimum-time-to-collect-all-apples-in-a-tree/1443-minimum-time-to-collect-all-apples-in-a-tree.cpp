class Solution {
public:
    int dfs(int idx, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &hasApple){
        if(vis[idx]) return 0;
        int time = 0;
        vis[idx] = true;
        
        for(int i: adj[idx]){
            time += dfs(i, adj, vis, hasApple);
        }
       
        if((time>0) || (hasApple[idx]))
        {
            time++;
        }
        
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        
        }
        int r= dfs(0, adj, vis, hasApple) -1;
        r*=2;
        
        return max(r,0);
        
    }
};