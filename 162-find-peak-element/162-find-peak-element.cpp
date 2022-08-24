class Solution {
public:
    //Approach 2
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
            
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e - s)/2;
            if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] > nums[mid+1])
                e = mid;
            else
                s = mid+1;
        }
        
        return s;
    }
    
    
    //Approach 1
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)
//             return 0;
        
//         if(nums[0]>nums[1])
//             return 0;
//         if(nums[n-1]>nums[n-2])
//             return n-1;
            
//         for(int i = 1; i<nums.size()-1; i++){
//             if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
//                 return i;
//         }
//         return -1;
//     }
};