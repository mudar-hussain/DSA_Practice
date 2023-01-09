class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int mid;
        while(low < high){
            mid = low + (high-low)/2;
            if(mid>0 && nums[mid] < nums[mid-1])
                return nums[mid];
            if(mid<n-1 && nums[mid]>nums[mid+1])
                return nums[mid+1];
            if(nums[mid]>nums[high])
                low = mid;
            else
                high = mid;
        }
        return nums[low];
        
    }
};