class Solution {
    
    bool isCyclic(vector<vector<int>> &adj, vector<int> &vis, int curr){
        if(vis[curr] == 2) return true;
        
        vis[curr] = 2;
        for(int i: adj[curr]){
            if(vis[i] != 1){
                if(isCyclic(adj, vis, i))
                    return true;
            }
        }
        
        vis[curr] = 1;
        return false;
    }
    
public:
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto i: p){
            adj[i[0]].push_back(i[1]);
            // adj[i[1]].push_back(i[0]);
        }
        
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                if(isCyclic(adj, vis, i))
                    return false;
            }
        }
        
        return true;
    }
};