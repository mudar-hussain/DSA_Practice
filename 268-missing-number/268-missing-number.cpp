class Solution {
public:
    //Approach 2
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i = 0; i<n; i++){
            ans ^= i;
            ans ^=  nums[i];
            
        }
        return ans;
        
    }
    //Approach 1
//     int missingNumber(vector<int>& nums) {
//         int  n  = nums.size();
//         int sum = (n*(n+1))/2;
//         for(int i = 0; i<n; i++){
//             sum -= nums[i];
//         }
        
//         return sum;
//     }
};