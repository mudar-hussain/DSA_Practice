class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = 0;
        int x = nums.size()-1;
        for(int i = nums.size()-1; i>=0; i--){
            if(i+nums[i] >= x){
                ans = 1; 
                x = i;
            }else
                ans = 0;
        }
        return ans;
    }
};