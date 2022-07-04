class Solution {
public:
    //Approach 2
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n+1, false);
        for(int i = 0; i<n; i++){
            if(nums[i] > 0 && nums[i]<=n)
                v[nums[i]] = true;
        }
        for(int i = 1; i<=n; i++){
            if(v[i] == false)
                return i;
        }
        return n+1;        
        
    }
    
    //Approach 1 (TLE)
    // int firstMissingPositive(vector<int>& nums) {
    //     int n = nums.size();
    //     int k = 0;
    //     for(int i = 0; i<n; i++){
    //         if(nums[i] > 0)
    //             nums[k++] = nums[i];
    //     }
    //     for(int i = 1; i<=k+1; i++){
    //         if(find(nums.begin(), nums.begin()+k, i) == nums.begin()+k)
    //             return i;
    //     }
    //     return 0;
    // }
};