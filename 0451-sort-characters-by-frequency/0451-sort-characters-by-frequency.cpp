class Solution {
public:
    static bool cmp(pair<int, char> a, pair<int, char> b){
        if(a.first == b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for(auto i: s){
            um[i]++;
        }
        vector<pair<int, char>> v;
        for(auto i = um.begin(); i!=um.end(); i++){
            v.push_back({i->second, i->first});
        }
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        for(auto i: v){
            for(int j = 0; j<i.first; j++){
                ans += i.second;
            }
        }
        return ans;
    }
};