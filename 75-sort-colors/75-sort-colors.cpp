class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int z = 0, t = n-1;
        for(int i = 0; i<n && i<=t; i++){
            if(nums[i]==0){
                swap(nums[i], nums[z]);
                z++;
            }else if(nums[i]==2){
                swap(nums[i], nums[t]);
                t--;
                if(nums[i] == 0 || nums[i] == 2) i--;
            }
            
        }
        
    }
};