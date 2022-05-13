class Solution {
public:
    //2nd Approach (Graph Coloring BFS)
    bool isB(vector<vector<int>> &graph, vector<int> &color, int i){
        queue<int> q;
        q.push(i);
        color[i] = 1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int ele: graph[curr]){
                if(color[ele] == color[curr]){
                    return false;
                }
                if(color[ele] == -1){
                    color[ele] = 1-color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
        if(n==0 || n==1) return true;
        vector<int> color(n+1, -1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1)
                if(!isB(graph, color, i))
                    return false;
        }
        return true;
    }
    
    //1st Approach (SET)
//     bool isBipartite(vector<vector<int>>& graph) {
//         unordered_set<int> A, B;
//         for (int i = 0; i < graph.size(); i++) {
//             if (B.find(i) == B.end() && A.find(i) == A.end()) {
//                 bool result = helper(graph, i, A, B);
//                 if (result == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
//     bool helper(vector<vector<int>> &graph, int current, unordered_set<int> &A, unordered_set<int> &B) {
//         A.insert(current);
//         for (int &child : graph[current]) {
//             if (A.find(child) != A.end()) {
//                 return false;
//             }
//             if (B.find(child) == B.end()) {
//                 B.insert(child);
//                 if (helper(graph, child, B, A) == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
};