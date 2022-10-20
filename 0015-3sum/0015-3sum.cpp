class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;            // O(3^k) k = no of triplets
        sort(nums.begin(), nums.end());     // O(NlogN)
        
        for(int i = 0; i<nums.size()-2; i++){   // O(N^2)
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int low = i+1, high = nums.size()-1;    
            while(low<high){                                
                if(nums[i] + nums[low] + nums[high] == 0){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(nums[i] + nums[low] + nums[high] < 0)
                    low++;
                else
                    high--;
            }
            
        }
        return ans;
    }
};
