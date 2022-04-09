class Solution {
public:
    //2nd Approach
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target))return {-1,-1};
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        return {x,y};    
    }
    //1st Approach
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int right = -1, left = -1;
//         int low = 0, high = n-1;
        
//         while(low<=high){
//             int mid = low+(high-low)/2;
//             if(nums[mid] == target){
//                 left = mid;
//                 high = mid-1;
//             }else if(target>nums[mid]){
//                 low = mid+1;
//             }else{
//                 high = mid-1;
//             }
//         }
//         low = 0, high = n-1;
//         while(low<=high){
//             int mid = low+(high-low)/2;
//             if(nums[mid] == target){
//                 right = mid;
//                 low = mid+1;
//             }else if(target>nums[mid]){
//                 low = mid+1;
//             }else{
//                 high = mid-1;
//             }
//         }
        
//         return {left, right};
//     }
};