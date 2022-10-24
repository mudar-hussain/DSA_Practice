class Solution {
public:
        int dp[301];
    bool solve(string &s, unordered_set<string> &st, int idx ){
        if(idx == s.length()){
            return dp[idx] = true;
        }
        if(dp[idx] != -1)
            return dp[idx];
        for(int i = idx; i<=s.length(); i++){
            if(st.find(s.substr(idx, i-idx+1)) != st.end())
                if(solve(s, st, i+1))
                    return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i: wordDict)
            st.insert(i);
        memset(dp, -1, sizeof(dp));
        return solve(s, st, 0);
    }
};