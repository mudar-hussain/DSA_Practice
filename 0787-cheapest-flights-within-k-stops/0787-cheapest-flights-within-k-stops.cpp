class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto i: flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> cost(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(k-->=0){
            int size = q.size();
            while(size--){
                int idx = q.front().first;
                int price = q.front().second;
                q.pop();
                for(auto i: adj[idx]){
                    if(cost[i.first] > price+i.second){
                        q.push({i.first, price+i.second});
                        cost[i.first] = price+i.second;
                    }
                }
            }
        }
        
        return cost[dst]==INT_MAX? -1: cost[dst];
        
    }
};