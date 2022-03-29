class Solution {
public:
    double myPow(double x, int n) {
        double num = n < 0 ? 1 / x : x;
        double product{1};
        n = abs(n);
        
        while(n){
            if(n & 1)
                product *= num;
            
            num *= num;
            
            n /= 2;
        }
        
        return product;    
    
    }
};