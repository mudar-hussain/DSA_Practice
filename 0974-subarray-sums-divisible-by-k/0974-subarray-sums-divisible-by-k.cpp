class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0] = 1;
        int count = 0;
        int sum = 0;
        int remainder = 0;
        for(int i: nums){
            sum += i;
            remainder = sum%k;
            if(remainder < 0)
                remainder += k;
            count += um[remainder];
            um[remainder]++;
        }
        return count;
    }
};