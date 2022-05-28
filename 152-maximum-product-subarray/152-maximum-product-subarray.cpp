class Solution {
public:
    //2nd Approach
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        int ans = nums[0], prod1 = nums[0], prod2 = nums[0];
        for(int i = 1; i<n; i++){
            int temp = max({nums[i], nums[i]*prod1, nums[i]*prod2});
            prod2 = min({nums[i], nums[i]*prod1, nums[i]*prod2});
            prod1 = temp;
            
            ans = max(ans, prod1);
            
        }
        return ans;
        
    }

    //1st Approach
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxLeft = INT_MIN;
    //     int maxRight = INT_MIN;
    //     int prod = 1;
    //     bool zero = false;
    //     for(auto i: nums){
    //         prod *= i;
    //         if(i == 0){
    //             zero = true;
    //             prod = 1;
    //             continue;
    //         }
    //         maxLeft = max(maxLeft, prod);
    //     }
    //     prod = 1;
    //     for(int i = n-1; i>=0; i--){
    //         prod *= nums[i];
    //         if(nums[i] == 0){
    //             zero = true;
    //             prod = 1;
    //             continue;
    //         }
    //         maxRight = max(maxRight, prod);
    //     }
    //     if(zero == true) 
    //         return max(max(maxLeft, maxRight), 0);
    //     return max(maxLeft, maxRight);
    // }
        
};