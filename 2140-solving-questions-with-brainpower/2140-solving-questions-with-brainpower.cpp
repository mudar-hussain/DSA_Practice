class Solution {
    long long dp[100001];
    long long solve(vector<vector<int>> &q, int idx){
        if(idx>=q.size())
            return 0;
        if(dp[idx] != -1){
            return dp[idx];
        }
        long long a = solve(q, idx+1);
        long long b = q[idx][0]+solve(q, idx+q[idx][1]+1);
        
        return dp[idx] = max(a, b);
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return solve(questions, 0);
    }
};