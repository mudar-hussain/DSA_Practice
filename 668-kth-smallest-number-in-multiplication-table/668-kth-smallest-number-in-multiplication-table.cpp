class Solution {
public:
    bool enough(int m, int n, int k, int mid){
        int count = 0;
        for(int i = 1; i<=m; i++){
            count += min(mid/i, n);
        }
        return count>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n;
        while(left < right){
            int mid = left + (right - left)/2;
            if(enough(m, n, k, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
};