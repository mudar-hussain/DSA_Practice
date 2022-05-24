class Solution {
public:
    //Approach 2 (Disjoint Optimised)
    int find(int i, vector<int> &parent){
        if(parent[i] == -1)
            return i;
        return find(parent[i], parent);
            
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,-1);
        vector<int> rank(n+1, 0);
        for(auto i: edges){
            int p1 = find(i[0], parent);
            int p2 = find(i[1], parent);
            if(p1 == p2)
                return i;
            if(rank[p1] < rank[p2])
                parent[p1] = p2;
            else if(rank[p1] > rank[p2])
                parent[p2] = p1;
            else{
                parent[p1] = p2;
                rank[p2]++;
            }
        }
        return {};
        
    }
    
    //Approach 1 (Disjoint)
    // int find(int i, vector<int> &p){
    //     if(p[i] == -1)
    //         return i;
    //     return find(p[i], p);
    // }
    // vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //     int n = edges.size();
    //     vector<int> parent(n+1, -1);
    //     for(auto i: edges){
    //         int p1 = find(i[0], parent);
    //         int p2 = find(i[1], parent);
    //         if(p1 == p2)
    //             return i;
    //         parent[p1] = p2;
    //     }
    //     return {};
    // }
};