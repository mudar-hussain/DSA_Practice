// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[201][201][2];
    int solve(string &s, int i, int j, bool isTrue){
        if(i>j)
            return 1;
        if(i == j)
            if(isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
            
        int ans = 0;
        
        for(int k = i+1; k<j; k+=2){
            int lt = solve(s, i, k-1, true);
            int lf = solve(s, i, k-1, false);
            int rt = solve(s, k+1, j, true);
            int rf = solve(s, k+1, j, false);
            
            switch(s[k]){
                case '|':{
                    if(isTrue == true)
                        ans += lt*rt + lf*rt + lt*rf;
                    else
                        ans += lf*rf;
                    break;
                }
                case '&':{
                    if(isTrue == true)
                        ans += lt*rt;
                    else
                        ans += lf*rf + lf*rt + lt*rf;
                    break;
                }
                case '^':{
                    if(isTrue == true)
                        ans += lf*rt + lt*rf;
                    else
                        ans += lf*rf + lt*rt;
                    break;
                }
                
            }
        }
        
        return dp[i][j][isTrue] = ans%1003;
            
    }
    
    int countWays(int n, string s){
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.length()-1, true);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends