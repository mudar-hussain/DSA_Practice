class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size <=1) return;
        int mx = INT_MIN;
        for(int i = size-1; i>=0; i--){
            if(nums[i]>=mx){
                mx = nums[i];
            }
            else {
                int idx = size-1;
                for(idx = size-1; idx>i; idx--){ 
                    if(nums[idx]>nums[i]) break;
                }
                swap(nums[i], nums[idx]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
        
    }
};