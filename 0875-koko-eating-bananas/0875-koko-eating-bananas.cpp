class Solution {
public:
    bool isFeasible(vector<int>& piles, int capacity, int h){
        long long sum = 0;
        for(auto i: piles){
            if(sum +  ceil((double)i/capacity)>h)
                return false;
            sum += ceil((double)i/capacity);
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i: piles)
            maxi = max(maxi, i);
        int low = 0;
        int high = maxi;
        while(low<high){
            int mid = low + (high-low)/2;
            if(isFeasible(piles, mid, h))
                high = mid;
            else 
                low = mid+1;
        }
        return low;
    }
};