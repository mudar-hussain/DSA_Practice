class Solution {
    bool isDoable(vector<int>& piles, int capacity, int h){
        
        if(capacity == 0)
            return false;
        
        for(int i: piles){
            h -= (i/capacity);
            if(i%capacity) h--;
            if(h<0)
                break;
        }
        return h>=0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, mid, high = 0, ans = INT_MAX;
        for(int i: piles){
            high = max(high, i);
        }
        
        while(low<=high){
            mid = low + (high - low)/2;
            if(isDoable(piles, mid, h)){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};