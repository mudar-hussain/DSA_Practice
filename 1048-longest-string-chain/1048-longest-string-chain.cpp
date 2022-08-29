class Solution {
    int dp[1001][1001];
public:
    bool isValid(string& a, string& b){
        
        if(a.length() == b.length() || a.length() > b.length()+1)
            return false;
        int allow = 1;
        int i = 0, j = 0;
        while(i<a.length()){
            if(j<b.length() && a[i] == b[j])
                i++,j++;
            else
                i++;
        }
        if(i == a.length() && j == b.length())
            return true;
        
        return false;
    }
    int solve(vector<string>& words, int idx, int prev){
        if(idx > words.size()){
            return 0;
        }
        if(dp[idx][prev] != -1)
            return dp[idx][prev];
        
        int a = 0, b = 0;
        if(prev == 0 || isValid(words[idx-1], words[prev-1]))
            a = 1+solve(words, idx+1, idx);
        
        b = solve(words, idx+1, prev);
        
        return dp[idx][prev] = max(a,b);
        
        
        
    }
    
    static bool cmp(string& a, string& b){
        return a.length()<b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        memset(dp, -1, sizeof(dp));
        return solve(words, 1, 0);
        
    }
};










