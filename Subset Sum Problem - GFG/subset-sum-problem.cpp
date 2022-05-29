// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
//2nd Approach
    bool solve(vector<int> &arr, vector<vector<int>> &dp, int n, int sum){
        if(sum == 0){
            return true;
        }
        if(n == -1 || sum < 0)
            return false;
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
            
        if(arr[n] <= sum)
        return dp[n][sum] = (solve(arr, dp, n-1, sum-arr[n]) || solve(arr, dp, n-1, sum));
        
        return dp[n][sum] = solve(arr, dp, n-1, sum);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, dp, n-1, sum);
    }
    
    //2nd Approach
    // bool dp(vector<int> &arr, int n, int sum){
    //     if(sum == 0){
    //         return true;
    //     }
    //     if(n == -1 || sum < 0)
    //         return false;
            
    //     return (dp(arr, n-1, sum-arr[n]) || dp(arr, n-1, sum));
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n = arr.size();
        
    //     return dp(arr, n-1, sum);
    // }
    
    
//1st Approach
    // bool isSubsetSum(vector<int>arr, int sum){
    //     // code here 
    //     int n = arr.size();
    //     int dp[n+1][sum+1];
    //     for(int i = 0; i<=n; i++){
    //         for(int j = 0; j<=sum; j++){
    //             if(i == 0 || j == 0){
    //                 if(i == 0)
    //                     dp[i][j] = false;
    //                 if(j == 0)
    //                     dp[i][j] = true;
    //             }else{
    //                 if(arr[i-1] <= j){
    //                     dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
    //                 }
    //                 else{
    //                     dp[i][j] = dp[i-1][j];
    //                 }
    //             }
    //         }
    //     }
    //     return dp[n][sum];
    // }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends