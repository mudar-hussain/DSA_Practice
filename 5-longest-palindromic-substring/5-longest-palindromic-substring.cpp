class Solution {
    
public:
    //2nd Approach (Center)
    
    string helper(string s, int i, int j){
        if(i<0) return s.substr(0,j-i-1);
        else if(j==s.length()) return s.substr(i+1,j-i-1);
        
        if(s[i] != s[j]) return s.substr(i+1,j-i-1);
        
        return  helper(s, i-1, j+1);;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int ans_length = 1;
        string ans = s.substr(0,1);
        for(int i = 1; i<n; i++){
            if(s[i] == s[i-1]){
                string temp = helper(s, i-1, i);
                if(ans_length < temp.length()){
                    ans_length = temp.length();
                    ans = temp;
                }
            }
            // if(ans_length == s.length() || ans_length == s.length()-1) return ans;
            if(i<n-1 && s[i-1] == s[i+1]){
                string temp = helper(s, i-1, i+1);
                if(ans_length < temp.length()){
                    ans_length = temp.length();
                    ans = temp;
                }
            }
            
            if(ans_length == s.length()) return ans;
            if(ans_length == s.length()-1 && i>=n/2) return ans;
            
        }
        return ans;
    }
    
    //-------------------------------------------------------------------------------
    //1st Approach (Worst Case)
//     bool isPalindrome(string s, int i, int j, vector<vector<int>> &dp){
//         int a = i, b = j;
//         while(i<=j){
//             if(dp[i][j]) return true;
//             if(s[i] != s[j]) return false;
//             i++;
//             j--;
            
//         }
//         dp[a][b] = 1;
//         return true;
//     }
//     string helper(string s, int i, int j, vector<vector<int>> &dp){
//         if(i==j) return s.substr(i, 1);
        
//         if(isPalindrome(s, i, j, dp)) return s.substr(i, j-i+1);
        
//         string a = helper(s, i+1, j, dp);
//         string b = helper(s, i, j-1, dp);
        
//         if(a.length()>=b.length()) return a;
        
//         return  b;
//     }
//     string longestPalindrome(string s) {
//         int n = s.length();
//     vector<vector<int>> dp(n,vector<int>(n,0));
//         return helper(s, 0, n-1, dp);
//     }
};