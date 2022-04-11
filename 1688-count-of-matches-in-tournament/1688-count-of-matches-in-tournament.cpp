class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0, rem = 0;
        while(n){
            n += rem;
            rem = n%2;
            n /= 2;
            ans += n;
        }
        return ans;
    }
};