class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pmini = nums[0], pmaxi = nums[0], result = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int temp = max({nums[i], nums[i]*pmini, nums[i]*pmaxi});
            pmini = min({nums[i], nums[i]*pmini, nums[i]*pmaxi});
            pmaxi = temp;
            result = max(result, pmaxi);
            
        }
        return result;
    }
};