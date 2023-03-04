class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mini = 0, maxi = 0;
        bool minFound = false, maxFound = false;
        int start = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            
            if(nums[i] == minK){
                minFound = true;
                mini = i;
            }
            
            if(nums[i] == maxK){
                maxFound = true;
                maxi = i;
            }
            
            if(minFound && maxFound){
                ans += (min(mini, maxi) - start + 1);
            }
        }
        return ans;
    }
    

};




















