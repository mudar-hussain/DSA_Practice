class Solution {
public:
    int isFeasible(vector<int>& piles, int capacity, int h){
        int sum = 0;
        for(int i: piles){
            sum += ceil((double)i/capacity);
            if(sum>h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for(int i: piles){
            right = max(right, i);
        }
        while(left < right){
            int mid = left + (right - left)/2;
            if(isFeasible(piles, mid, h))
                right = mid;
            else 
                left = mid+1;
        }
        return left;
    }
};