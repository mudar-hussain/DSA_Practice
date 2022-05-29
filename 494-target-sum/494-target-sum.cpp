class Solution {
public:
    void knapsack(vector<int> &nums, int n, int target, int &ans){
        if(n == -1 && target == 0){
            ans++;
            return;
        }else if(n == -1){
            return;
        }
        knapsack(nums, n-1, target-nums[n], ans);
        knapsack(nums, n-1, target+nums[n], ans);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        knapsack(nums, n-1, target, ans);
        return ans;
    }
};