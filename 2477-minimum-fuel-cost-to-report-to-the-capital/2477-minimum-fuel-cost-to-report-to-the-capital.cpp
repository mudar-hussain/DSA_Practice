class Solution {
    vector<vector<int>> adj;
        long long ans = 0;
    long long dfs(int seats, int idx, int parent){
        long long people = 1;
        for(int i: adj[idx]){
            if(i != parent)
                people += dfs(seats, i, idx);
        }
        
        if(idx>0){
            ans += (people + seats -1)/seats;
        }
        
        return people;
    }
    
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        adj.resize(n+1);
        for(auto e: roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(seats, 0, -1);
        
        return ans;
    }
};