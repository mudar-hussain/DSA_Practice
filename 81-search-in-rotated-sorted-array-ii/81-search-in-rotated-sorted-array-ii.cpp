class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1)
            if(nums[0] == target)
                return true;
            else 
                return false;
        int  low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target == nums[mid] || nums[low] == target || nums[high] == target) 
                return true;
            else if(nums[low] == nums[high]){
                low++;
                high--;
            }
                
            else if(nums[mid]>= nums[low]){
                if(target>=nums[low] && target<nums[mid]){
                    high = mid-1;
                }else low = mid+1;
            }else{
                if(target>nums[mid] && target<=nums[high]){
                    low = mid+1;
                }else high = mid-1;
            }
        }
        return false;
    }
};