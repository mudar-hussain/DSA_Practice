class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i: nums){
            um[i]++;
        }
        int ans = 0;
        for(auto i: um){
            if(i.second == 1)
                ans += i.first;
        }
        return ans;
    }
};