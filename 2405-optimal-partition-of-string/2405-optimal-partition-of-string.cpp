class Solution {
//     vector<int> dp;
//     int solve(string& s, int &n, int idx){
//         if(idx >= n){
//             return 0;
//         }
//         if(dp[idx] != -1)
//             return dp[idx];
        
//         int curr = INT_MAX;
//         vector<int> v(26,0);
//         for(int i = idx; i<n; i++){
//             if(v[s[i]-'a'] == 1)
//                 break;
//             v[s[i] - 'a'] = 1;
//             curr = min(curr, 1+solve(s, n, i+1));
//         }
//         return dp[idx] = curr;
        
//     }
public:
    int partitionString(string s) {
        int n = s.length();
        int dp[26];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(char c: s){
            if(dp[c-'a'] != 0){
                ans++;
                memset(dp, 0, sizeof(dp));
            }
            dp[c-'a']++;
        }
        
        return ans+1;
    }
};