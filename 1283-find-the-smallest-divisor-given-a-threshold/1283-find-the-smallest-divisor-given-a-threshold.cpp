class Solution {
public:
    int ddivide(vector<int>&nums, int mid){
       
        int result = 0;
        for(int i: nums){
            result += ceil((double)i/mid);
        }
        return result;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = 0;
        for(int i: nums){
            high = max(high, i);
        }
        if(nums.size() == threshold)
            return high;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high - low)/2;
            int result = ddivide(nums, mid);
            if(result <= threshold){
                ans = min(ans, mid);
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};