//2nd Approach (BFS)

class Solution {
public:
    
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
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans++;
            
            for(int i: adj[curr]){
                inDeg[i]--;
                if(inDeg[i] == 0)
                    q.push(i);
            }
        }
        
        
        
        return ans == n;
    }
};


//1st Approach (Topological Sort - DFS)

// class Solution {
    
//     bool isCyclic(vector<vector<int>> &adj, vector<int> &vis, int curr){
//         if(vis[curr] == 2) return true;
        
//         vis[curr] = 2;
//         for(int i: adj[curr]){
//             if(vis[i] != 1){
//                 if(isCyclic(adj, vis, i))
//                     return true;
//             }
//         }
        
//         vis[curr] = 1;
//         return false;
//     }
    
// public:
    
//     bool canFinish(int n, vector<vector<int>>& p) {
//         vector<int> vis(n, 0);
//         vector<vector<int>> adj(n);
//         for(auto i: p){
//             adj[i[0]].push_back(i[1]);
//             // adj[i[1]].push_back(i[0]);
//         }
        
//         for(int i = 0; i<n; i++){
//             if(vis[i] == 0){
//                 if(isCyclic(adj, vis, i))
//                     return false;
//             }
//         }
        
//         return true;
//     }
// };