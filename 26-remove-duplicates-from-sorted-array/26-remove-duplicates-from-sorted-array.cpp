class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, i=0;
        while(i<n){
            nums[ans] = nums[i];
            while(i+1<n && nums[i]==nums[i+1] ) i++;
            ans++;i++;
        }
        return ans;
    }
};