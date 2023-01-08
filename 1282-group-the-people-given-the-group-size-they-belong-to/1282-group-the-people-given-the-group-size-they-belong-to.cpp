class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> um;
        for(int i = 0; i<groupSizes.size(); i++){
            um[groupSizes[i]].push_back(i);
        }
        for(auto i: um){
            vector<int> v;
            for(int j: i.second){
                v.push_back(j);
                if(v.size() == i.first){
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};