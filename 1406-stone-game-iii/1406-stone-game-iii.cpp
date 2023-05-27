class Solution {
    int n;
    vector<int> dp;
    
    int solve(vector<int> &stoneValue, int idx){
        if(idx>=n)
            return 0;
        if(dp[idx] >INT_MIN)
            return dp[idx];
        int sum  = 0;
        for(int i = 0; i<3 && idx+i<n; i++){
            sum += stoneValue[idx+i];
            dp[idx] = max(dp[idx], sum - solve(stoneValue, idx+i+1));
        }
        
        return dp[idx];
    }
    
    public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n, INT_MIN);
        int score = solve(stoneValue, 0);
        if(score>0)
            return "Alice";
        else if(score<0)
            return "Bob";
        else
            return "Tie";
    }
};