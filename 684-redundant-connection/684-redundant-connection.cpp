class Solution {
public:
    int find(int i, vector<int> &p){
        if(p[i] == -1)
            return i;
        return find(p[i], p);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, -1);
        for(auto i: edges){
            int p1 = find(i[0], parent);
            int p2 = find(i[1], parent);
            if(p1 == p2)
                return i;
            parent[p1] = p2;
        }
        return {};
    }
};