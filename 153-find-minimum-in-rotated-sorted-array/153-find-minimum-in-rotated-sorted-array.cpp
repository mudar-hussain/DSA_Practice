class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int mini = nums[0];
        int low = 0, high = n-1;
        while(low<high){
            int mid = low + (high-low)/2;
            mini = min(mini, nums[mid]);
            mini = min(mini, nums[low]);
            mini = min(mini, nums[high]);
                
            if(nums[mid]>nums[low])
                low = mid+1;
            else high = mid-1;
        }
        return mini;
    }
};