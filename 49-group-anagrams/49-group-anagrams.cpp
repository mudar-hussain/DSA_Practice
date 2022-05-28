class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> p;
        for(auto it: strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            p[temp].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it: p){
            ans.push_back(it.second);
        }
        return ans;
    }
};