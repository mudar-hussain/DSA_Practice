class Solution {
public:
    int findParent(int n, vector<int> parent){
        if(n == parent[n]) return n;
        return findParent(parent[n], parent);
                                 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);
        vector<int> ans;
        for(int i = 0; i<=n; i++)
            parent[i] = i;
        for(auto node: edges){
            int n1 = node[0], n2 = node[1];
            int p1 = findParent(n1, parent);
            int p2 = findParent(n2, parent);
            if(p1 == p2){
                ans.push_back(n1);
                ans.push_back(n2);
                return ans;
            }else{
                parent[p1] = p2;
            }
        }
        return ans;
    }
};