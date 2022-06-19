class Solution {
public:
    bool isFeasible(vector<int>& nums, int capacity, int d){
        int days = 1, t = 0;
        for(int i: nums){
            t += i;
            if(t>capacity){
                t = i;
                days++;
                if(days > d)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for(int i: nums){
            left = max(left, i);
            right += i;
        }
        while(left<right){
            int mid = left + (right - left)/2;
            if(isFeasible(nums, mid, m))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};