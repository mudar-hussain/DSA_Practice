class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i: nums){
            um[i]++;
        }
        vector<pair<int, int>> v;
        for(auto i = um.begin(); i!=um.end(); i++){
            v.push_back({i->second, i->first});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(int i = 0; i<v.size(); i++){
            for(int j = 0; j<v[i].first; j++){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};