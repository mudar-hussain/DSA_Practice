class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
		int count = 1;
        
        if(n <= 2)
            return 0;
       
        for(long long int i = 3; i<n; i+=2){ 
            if(prime[i]){
                count++;
                for(long int j = i*i ; j <n; j += i * 2)
                    prime[j] = false;
            }
        }
        return count;
    }
};