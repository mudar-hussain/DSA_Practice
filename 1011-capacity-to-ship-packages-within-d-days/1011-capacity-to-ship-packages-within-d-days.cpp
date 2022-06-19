class Solution {
public:
    bool isFeasible(vector<int>& w, int capacity, int d){
        int days = 1, t = 0;
        for(int i: w){
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
    int shipWithinDays(vector<int>& w, int d) {
        int left = 0, right = 0;
        for(int i: w){
            left = max(left, i);
            right += i;
        }
        while(left<right){
            int mid = left + (right - left)/2;
            if(isFeasible(w, mid, d))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};