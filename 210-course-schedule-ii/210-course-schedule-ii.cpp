class Solution {
public:
    bool isCyclic(vector<vector<int>> &adj, vector<int> &vis, int cur){
        if(vis[cur] == 2)
            return true;
        vis[cur] = 2;
        for(int i: adj[cur]){
            if(vis[i] != 1)
                if(isCyclic(adj, vis, i))
                    return true;
        }
        vis[cur] = 1;
        return false;
    }
    
    bool detectCycle(int n, vector<vector<int>> &adj){
        vector<int> vis(n+1, 0);
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                if(isCyclic(adj, vis, i))
                    return true;
            }
        }
        return false;
    }
    
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int cur, stack<int> &s){
        vis[cur] = true;
        for(int i: adj[cur]){
            if(vis[i] == false)
                dfs(adj, vis, i,s);
        }
        s.push(cur);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> ans;
        vector<vector<int>> adj(n+1);
        for(auto i: p){
            adj[i[1]].push_back(i[0]);
            
        }
        if(detectCycle(n, adj))
            return ans;
        
        vector<bool> vis(n+1, false);
        stack<int> s;
        
        for(int i = 0; i<n; i++){
            if(vis[i] == false)
                dfs(adj, vis, i,s);
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        
        
        
        
    }
};









