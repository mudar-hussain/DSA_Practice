class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26,INT_MAX);
        vector<string> ans;
        for(string s: words){
            vector<int> v(26, 0);
            for(char c: s){
                v[c - 'a']++;
            }
            for(int i = 0;i<26; i++){
                cnt[i] = min(cnt[i], v[i]);
            }
        }
        for(int i = 0; i<26; i++){
            for(int j = 0; j<cnt[i]; j++){
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
        
    }
};