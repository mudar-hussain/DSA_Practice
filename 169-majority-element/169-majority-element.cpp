class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> checked;
        for(int i = 0; i<n; i++){
            if(find(checked.begin(), checked.end(), nums[i]) == checked.end()){
                if(count(nums.begin()+i, nums.end(), nums[i]) > n/2)
                    return nums[i];
                checked.push_back(nums[i]);
            }
        }
        
        return -1;
    }
};