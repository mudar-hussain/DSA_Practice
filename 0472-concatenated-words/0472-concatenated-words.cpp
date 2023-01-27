class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> s;
        for(auto w: words){
            s.insert(w);
        }
        for(auto word: words){
            int n = word.size();
            vector<int> dp(n+1, 0);
            dp[0] = 1;
            for(int i = 0; i<n; i++){
                if(!dp[i]) continue;
                for(int j = i+1; j<=n; j++){
                    if(j-i<n && s.find(word.substr(i, j-i)) != s.end())
                        dp[j] = 1;
                }
                if(dp[n] == 1){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
        
    }
};