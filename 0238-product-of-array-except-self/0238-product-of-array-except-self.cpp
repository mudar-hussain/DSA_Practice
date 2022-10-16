class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        int product = 1;
        for(int i: nums){
            if(i == 0)
                zeros++;
            else product *= i;
        }
        vector<int> v(nums.size(), 0);
        if(zeros>1){
            return v;
        }
        for(int i = 0; i<nums.size(); i++){
            if(zeros == 1){
                if(nums[i] == 0)
                    v[i] = product;
            }else
                v[i] = product/nums[i];
        }
        return v;
    }
};