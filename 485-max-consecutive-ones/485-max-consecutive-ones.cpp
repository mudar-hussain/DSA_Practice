class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, curr = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1) {
                curr++;
                ans = max(ans,curr);
            }else curr = 0;
        }
        return ans;
    }
};