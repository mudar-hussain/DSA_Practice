class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<3)
            return ans;
        sort(nums.begin(), nums.end());
        if(nums[0] > 0)
            return ans;
        
        for(int i = 0; i<n-2; i++){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int low = i+1, high = n-1;
            int sum = 0;
            while(low<high){
                sum = nums[i] + nums[low] + nums[high];
                if(sum<0)
                    low++;
                else if(sum>0)
                    high--;
                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
            }
        }
        return ans;
    }
};























