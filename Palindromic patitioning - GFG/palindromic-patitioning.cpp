// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    
    int solve(string &s, vector<vector<int>> &dp, int i, int j){
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(i>=j || isPalindrome(s, i, j)){
            return dp[i][j] =0;
        }
        
        int mn = INT_MAX;
        for(int k = i; k<j; k++){
            // if(isPalindrome(s, i, k)){
                int temp = 1+solve(s, dp, i, k)+solve(s, dp, k+1, j);
                mn = min(mn, temp);
            // }
        }
        return dp[i][j] = mn;
    }
    
    
    int palindromicPartition(string s)
    {
        // code here
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, dp, 0, n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends