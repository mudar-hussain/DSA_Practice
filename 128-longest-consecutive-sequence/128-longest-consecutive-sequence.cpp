class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        int ans = 1,prev = nums[0],curr = 1;
        while(j<n){
            if(nums[j] == prev+1){
                curr++;
            }
            else if(nums[j] != prev){
                curr = 1;
            }
            prev = nums[j];
            ans = max(ans, curr);
            
            j++;
        }
        return ans;
    }
};