class Solution {
public:
    
    bool isCycle(vector<vector<int>> &adj, vector<int> &vis, int idx){
        if(vis[idx] == 2)
            return true;
        vis[idx] = 2;
        
        for(int i: adj[idx]){
            if(vis[i] != 1)
                if(isCycle(adj, vis, i))
                    return true;
        }
        vis[idx] = 1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto e: prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(numCourses, 0);
        
        for(int i = 0; i<numCourses; i++){
            if(vis[i] == 0)
                if(isCycle(adj, vis, i))
                    return false;
        }
        
        return true;
        
        
        
        
    }
};