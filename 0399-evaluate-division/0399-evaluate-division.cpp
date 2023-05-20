class Solution {
    map<string, double> mp;
    map<string, vector<string>> graph;
    
    void dfs(double &val, bool &found, string start, string end, map<string, int> &visited){
        if(visited[start] == 1 || found == true)
            return;
        
        visited[start] = 1;
        
        for(auto child : graph[start]){
            val *= mp[start + "->" + child];
            if(child == end){
                found = true;
                return;
            }
            
            dfs(val, found, child, end, visited);
            
            if(found == true){
                return;
            }else{
                val /= mp[start + "->" + child];
            }
        }
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(int i = 0; i<equations.size(); i++){
            mp[equations[i][0] + "->" + equations[i][1]] = values[i];
            mp[equations[i][1] + "->" + equations[i][0]] = 1/values[i];
            
            graph[equations[i][0]].push_back(equations[i][1]);
            graph[equations[i][1]].push_back(equations[i][0]);
            
        }
        double val;
        bool found;
        for(auto i: queries){
            if(graph.find(i[0]) == graph.end() || graph.find(i[1]) == graph.end()){
                ans.push_back(-1);
                continue;
            }
                
            val = 1;
            found = false;
            
            map<string, int> visited;
            
            if(i[0] == i[1])
                found=true;
            else
                dfs(val, found, i[0], i[1], visited);
            
            if(found == true){
               ans.push_back(val); 
            }else{
                ans.push_back(-1);
            }
            
        }
        
        return ans;
    }
};