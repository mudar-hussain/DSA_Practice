class Solution {
public:
    int mySqrt(int x) {
        if(x<=0) return x;
        long s = 1;
        long e = x;
        while(s<e-1){
            long mid = s + (e-s)/2;
            long sqr = mid*mid;
            if(sqr == x) return (int)mid;
            else if(sqr<x) s = mid;
            else e = mid;
        }
        return (int) s;
    }
};