class Solution {
public:
    int solve(vector<int> &nums, int f, int s){
        int n = nums.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        int cursum = 0;
        for(int i = 0; i<n; i++){
            cursum += nums[i];
            if(i<f){
                dp1[i] = cursum;
            }
            else{
                cursum -= nums[i-f];
                dp1[i] = max(cursum, dp1[i-1]);
            }
        }
        cursum = 0;
        for(int i = n-1; i>=0; i--){
            cursum += nums[i];
            if(i+s>=n){
                dp2[i] = cursum;
            }
            else{
                cursum -= nums[i+s];
                dp2[i] = max(cursum, dp2[i+1]);
            }
        }
        
        int ans = 0;
        for(int i = f-1; i<(n-s); i++){
            ans = max(ans, dp1[i] + dp2[i+1]);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        return max(solve(nums, f, s), solve(nums, s, f));
        
        
    }
};