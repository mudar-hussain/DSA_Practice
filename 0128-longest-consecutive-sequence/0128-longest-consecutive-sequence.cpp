class Solution {
public:
    int dfs(unordered_map<int, int>& um, int i){
        int res = 0;
        if(um.find(i+1) != um.end() && um[i+1] == 0){
            um[i+1] = 1;
            res += 1+ dfs(um, i+1);
        }
        if(um.find(i-1) != um.end() && um[i-1] == 0){
            um[i-1] = 1;
            res += 1+ dfs(um, i-1);
        }
        
        return res;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i: nums)
            um[i] = 0;
        int ans = 1;
        for(int i: nums){
            if(um[i] == 0)
                ans = max(ans, dfs(um, i));
        }
        return nums.size()?ans:0;
    }
};