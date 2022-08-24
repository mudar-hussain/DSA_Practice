class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> um;
        for(int i: nums){
            sum += i;
            if(sum == k)
                count++;
            // if(um.find(sum-k) != um.end()){
                count += um[sum-k];
            // }
            um[sum]++;
        }
        return count;
    }
};