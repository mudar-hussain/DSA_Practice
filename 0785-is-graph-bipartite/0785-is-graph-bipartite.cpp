class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int idx){
        
        for(int i: graph[idx]){
            if(color[idx] == color[i]){
                return false;
            }
            if(color[i] == -1){
                color[i] = 1-color[idx];
                if(dfs(graph, color, i) == false){
                    return false;
                }
            }
            
        }
        return true;
        
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 0 || n == 1) return true;
        vector<int> color(n+1, -1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                color[i] = 1;
                if(dfs(graph, color, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};