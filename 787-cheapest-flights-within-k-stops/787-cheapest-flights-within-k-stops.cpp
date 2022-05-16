class Solution {
    
public:
    //2nd Approach (BFS)
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        if(flights.size() == 0) return -1;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto i: flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> vis(n, INT_MAX);
        vis[src] = 0;
        
        queue<pair<int, int>> q;
        q.push({src, 0});   //{source, price}
        
        while(k>=0){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto [idx, price] = q.front();
                q.pop();
                
                for(auto [next, wt]: adj[idx]){
                    if(vis[next] <= price+wt)
                        continue;
                    q.push({next, price+wt});
                    vis[next] = price+wt;
                }
            }
            k--;
            
        }
        return vis[dst] == INT_MAX? -1:vis[dst];
        
            
    }
    
    //1st Approach ( DFS )
//     void dfs(vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int src, int dst, int &ans, int k, int curr_fare){
//         if(k<-1) return;
//         if(src == dst){
//             ans = min(ans, curr_fare);
//             return;
//         }
        
//         vis[src] = true;
//         for(auto i: adj[src]){
//             if(vis[i.first] == false && curr_fare+i.second < ans){
//                 dfs(adj, vis, i.first, dst, ans, k-1, curr_fare+i.second);
//             }
//         }
//         vis[src] = false;
        
//     }
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         int ans  = INT_MAX;
//         vector<vector<pair<int, int>>> adj(n+1);
//         vector<bool> vis(n+1, false);
//         for(auto i : flights){
//             adj[i[0]].push_back({i[1], i[2]});
//         }
//         dfs(adj, vis, src, dst, ans, k, 0);
        
//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
};