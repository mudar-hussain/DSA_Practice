class Solution {
    int dp[2001][2001];
    
    int solve(vector<int>& arr1, vector<int>& arr2, int parent, int i, int j){
        if(i>=arr1.size()){
            return 0;
        }
        
        j = upper_bound(arr2.begin()+j, arr2.end(), parent) - arr2.begin();
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int take = 2001, notTake = 2001;
        if(j < arr2.size()){
            take = solve(arr1, arr2, arr2[j], i+1, j+1) + 1;
        }
        if(arr1[i] > parent){
            notTake = solve(arr1, arr2, arr1[i], i+1, j);
        }
        
        return dp[i][j] = min(take, notTake);
        
    }
    
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        memset(dp, -1, sizeof(dp));
        
        
        int ans = solve(arr1, arr2, -1, 0, 0);
        
        if(ans == 2001)
            return -1;
        else
            return ans;
        
    }
};