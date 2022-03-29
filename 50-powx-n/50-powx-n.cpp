class Solution {
public:
    double solve(double x, long n){
        if(n==0) return 1;
        if(n<0) return solve(1/x, -1*(n));
        
        return n%2? x*solve(x*x, n/2): solve(x*x, n/2);
    }
    double myPow(double x, int n) {
        
        return solve( x, 1l * n);
//         double num = n < 0 ? 1 / x : x;
//         double product{1};
//         n = abs(n);
        
//         while(n){
//             if(n & 1)
//                 product *= num;
            
//             num *= num;
            
//             n /= 2;
//         }
        
//         return product;    
    
    }
};