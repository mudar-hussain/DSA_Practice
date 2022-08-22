class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long xx = x;
        if(xx<0){
            xx = -xx;
            neg = true;
        }
        long long reversed = 0;
        while(xx){
            reversed *= 10;
            reversed += xx%10;
            xx /= 10;
        }
        if(reversed > INT_MAX)
            return 0;
        if(neg)
            return (int)-reversed;
        else
            return (int)reversed;
    }
};