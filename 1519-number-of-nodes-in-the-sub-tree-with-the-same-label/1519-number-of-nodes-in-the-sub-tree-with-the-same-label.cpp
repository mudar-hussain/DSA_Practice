class Solution {
public:
    void dfs(vector<vector<int>> &adj, string &labels, vector<int> &ans, vector<int> &freq, int node, int prevNode){
        int prevCount = freq[labels[node]-'a'];
        
        freq[labels[node] - 'a']++;
        
        for(int nextNode: adj[node]){
            if(prevNode == nextNode)
                continue;
            
            dfs(adj, labels, ans, freq, nextNode, node);
        }
        
        ans[node] = freq[labels[node]-'a'] - prevCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n,0);
        vector<int> freq(26,0);
        dfs(adj, labels, ans, freq, 0, 0);
        
        return ans;
    }
};