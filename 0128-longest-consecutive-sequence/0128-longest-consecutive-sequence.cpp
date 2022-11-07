class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        for(int i: nums)
            m[i]++;
        int prev = INT_MIN;
        int count = 0;
        int ans = 0;
        for(auto i: m){
            if(i.first == prev+1){
                count++;
            }else
                count = 1;
            ans = max(ans, count);
            prev = i.first;
        }
        return ans;
        
    }
};