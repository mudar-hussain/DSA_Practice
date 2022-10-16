class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pmax = nums[0], pmin = nums[0], result = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int temp = max({nums[i], nums[i]*pmax, nums[i]*pmin});
            pmin = min({nums[i], nums[i]*pmax, nums[i]*pmin});
            pmax = temp;
            result = max(result, pmax);
        }
        return result;
    }
};