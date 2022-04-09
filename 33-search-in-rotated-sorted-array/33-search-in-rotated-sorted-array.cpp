class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1, low = 0, high = n-1;
        int pivot;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target == nums[mid]) return mid;
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
        return -1;
    }
};












