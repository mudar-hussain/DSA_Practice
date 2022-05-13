class Solution {
public:
    //3rd Approach (Khans Algo)
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n,0);
        for(auto i: p){
            adj[i[1]].push_back(i[0]);
            inDeg[i[0]]++;
        }
        int ans = 0;
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(inDeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans++;
            for(int i: adj[cur]){
                inDeg[i]--;
                if(inDeg[i] == 0)
                    q.push(i);
            }
        }
        
        return ans == n;
        
        
            
    }
    
    //2nd Approach (Graph coloring:  0=unvisited, 1=processed, 2=processing)
    
//     bool isCyclic(vector<vector<int>> &adj, vector<int> &vis, int curr){
//         if(vis[curr] == 2) 
//             return true;
//         vis[curr] = 2;
//         for(int j: adj[curr]){
//             if(vis[j] != 1){
//                 if(isCyclic(adj, vis, j))
//                     return true;
//             }
//         }
//         vis[curr] = 1;
//         return false;
        
//     }
//     bool canFinish(int n, vector<vector<int>>& p) {
//         vector<vector<int>> adj(n+1);
//         for(auto i: p){
//             adj[i[0]].push_back(i[1]);
//         }
//         vector<int> vis(n+1, 0);
//         for(int i = 0; i<n; i++){
//             if(vis[i] == 0){
//                 if(isCyclic(adj, vis, i))
//                     return false;
//             }
//         }
//         return true;
        
//     }
    
    //1st Approach
//     bool isCyclic_util(vector<vector<int>> &adj, vector<bool> &vis, int curr){
//         if(vis[curr] == true) return true;
//         vis[curr] = true;
//         for(int i: adj[curr]){
//             if(isCyclic_util(adj, vis, i))
//                 return true;
//         }
//         vis[curr] = false;
//         return false;
//     }
    
//     bool isCyclic(vector<vector<int>> &adj, int n){
//         vector<bool> vis(n+1, false);
//         for(int i = 0; i<n; i++){
//             vis[i] = true;
//             for(int j: adj[i]){
//                 if(isCyclic_util(adj, vis, j))
//                     return true;
//             }
//             vis[i] = false;
//         }
//         return false;
//     }
//     bool canFinish(int n, vector<vector<int>>& p) {
//         vector<vector<int>> adj(n);
//         for(int i = 0; i<n; i++){
//             adj[i[0]].push_back(i[1]);
//         }
//         return !isCyclic(adj, n);
//     }
};