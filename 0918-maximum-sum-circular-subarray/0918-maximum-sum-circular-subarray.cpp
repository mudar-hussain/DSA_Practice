class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, currMaxSum = 0, currMinSum = 0;
        int mxarray = INT_MIN;
        int mnarray = INT_MAX;
        for(int i: nums){
            total += i;
            currMaxSum += i;
            currMinSum += i;
            mxarray = max(mxarray, currMaxSum);
            mnarray = min(mnarray, currMinSum);
            
            if(currMaxSum<0) currMaxSum = 0;
            if(currMinSum>0) currMinSum = 0;
        }
        
        return (total == mnarray)? mxarray: max(mxarray, total - mnarray);
    }
};