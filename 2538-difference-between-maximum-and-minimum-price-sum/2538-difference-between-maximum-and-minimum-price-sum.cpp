class Solution {
public:
   long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        using ll = long long;
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        ll ans = 0;
        function<pair<ll, ll>(int, int)> dfs = [&] (int u, int p) {
            pair<ll, ll> ret = {price[u], 0};
            for (int v: adj[u]) {
                if (v != p) {
                    auto [a, b] = dfs(v, u);
                    ans = max(ans, max(ret.first + b, ret.second + a));
                    ret.first = max(ret.first, a + price[u]);
                    ret.second = max(ret.second, b + price[u]);
                }
            }
            return ret;
        };
        dfs(0, -1);
        return ans;
    }
};