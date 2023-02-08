class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur_end = 0, nxt_end = 0, steps = 0;
        for(int i = 0; i<n; i++){
            if(i>cur_end){
                steps++;
                cur_end = nxt_end;
            }
            
            nxt_end = max(nxt_end, i+nums[i]);
        }
        return steps;
    }
};