class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        vector<string> ans;
        int n = tickets.size();
        for(int i = 0; i<n; i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        
        stack<string> s;
        s.push("JFK");
        while(!s.empty()){
            string src = s.top();
            if(adj[src].empty()){
                ans.push_back(src);
                s.pop();
            }else {
                auto dst = adj[src].begin();
                s.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



