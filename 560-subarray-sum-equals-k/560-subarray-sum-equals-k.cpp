class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> um;
        um[0] = 1;
        for(int i: nums){
            sum += i;
            if(um.find(sum-k) != um.end()){
                count += um[sum-k];
            }
            um[sum]++;
        }
        return count;
    }
};