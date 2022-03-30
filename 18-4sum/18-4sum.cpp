class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            int target3 = target - nums[i];
            for(int j = i+1; j<n; j++){
                int target2 = target3 - nums[j];
                
                int front = j+1;
                int back = n-1;
                while(front<back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum>target2) back--;
                    else if(two_sum<target2) front++;
                    else{
                        vector<int> qd;
                        qd.push_back(nums[i]);
                        qd.push_back(nums[j]);
                        qd.push_back(nums[front]);
                        qd.push_back(nums[back]);
                        sort(qd.begin(), qd.end());
                        ans.push_back(qd);
                        
                        while(front<back && nums[front] == qd[2]) front++;
                        
                        while(back>front && nums[back] == qd[3]) back--;
                    }
                }
                while(j<n-1 && nums[j] == nums[j+1]) j++;
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};