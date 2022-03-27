class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        // int n = nums.size();
        // int meh = 0, msf = nums[0];
        // for(int i = 0; i<n; i++){
        //     meh += nums[i];
        //     if(meh>msf){
        //         msf = meh;
        //     } 
        //     else if(meh<0){
        //         meh = 0;
        //     }
        // }
        // if(msf<0) msf = 0;
        // return msf;
        
        
        int sum = 0,mx = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            mx = max(mx, sum);
            sum = sum<0? 0:sum;
        }
        return mx;
        
    }
};