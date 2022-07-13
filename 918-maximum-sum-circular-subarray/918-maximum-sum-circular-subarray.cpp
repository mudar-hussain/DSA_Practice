class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int tsum = 0, max_st = INT_MIN, min_st = INT_MAX, max_cur = 0, min_cur = 0;
        for(int i = 0; i<n; i++){
            tsum += nums[i];
            
            max_cur = max_cur+nums[i];
            max_st = max(max_st, max_cur);
            max_cur = max(max_cur, 0);
            
            min_cur = min_cur+nums[i];
            min_st = min(min_st, min_cur);
            min_cur = min(min_cur, 0);
            
        }
        if(tsum == min_st)
            return max_st;
        return max(max_st, tsum-min_st);
    }
};