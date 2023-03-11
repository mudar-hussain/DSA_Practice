class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i+=2){
            if(i+1>=n){
                ans++;
                continue;
            }
            if(nums[i] == nums[i+1]){
                ans++;
                i--;
            }
        }
        return ans;
    }
};