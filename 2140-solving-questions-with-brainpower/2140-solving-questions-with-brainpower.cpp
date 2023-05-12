class Solution {
    long long solve(vector<vector<int>> &q, vector<long long> &dp, int idx){
        if(idx>=q.size())
            return 0;
        if(dp[idx] != -1){
            return dp[idx];
        }
        long long a = solve(q, dp, idx+1);
        long long b = q[idx][0]+solve(q, dp, idx+q[idx][1]+1);
        
        return dp[idx] = max(a, b);
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1, -1);
        return solve(questions, dp, 0);
    }
};