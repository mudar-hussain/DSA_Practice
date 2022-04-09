class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int right = -1, left = -1;
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                left = mid;
                high = mid-1;
            }else if(target>nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                right = mid;
                low = mid+1;
            }else if(target>nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return {left, right};
    }
};