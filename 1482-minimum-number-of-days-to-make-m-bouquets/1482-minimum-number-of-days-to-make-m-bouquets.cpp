class Solution {
public:
    int isFeasible(vector<int>& b, int& m, int& k, int& days){
        int count = 0;
        int adj = 0;
        for(int i: b){
            if(i>days)
                adj = 0;
            else{
                adj++;
                if(adj == k){
                    count++;
                    adj = 0;
                }
                if(count == m)
                    return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& b, int m, int k) {
        if(b.size()<m*k) return -1;
        
        int left = 1, right = 0;
        for(int i: b){
            right = max(right, i);
        }
        while(left < right){
            int mid = left + (right - left)/2;
            if(isFeasible(b, m, k, mid))
                right = mid;
            else 
                left = mid+1;
        }
        return left;
        
        
    }
};