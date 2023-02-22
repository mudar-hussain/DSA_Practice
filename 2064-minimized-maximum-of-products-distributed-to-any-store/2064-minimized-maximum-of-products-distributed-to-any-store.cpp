class Solution {
    
    bool isValid(vector<int> &quantities, int n, int maxQ){
        if(maxQ == 0)
            return false;
        int count = 0;
        for(int i: quantities){
            if(i % maxQ)
                count += (i/maxQ+1);
            else
                count += (i/maxQ);
        }
        
        return count<=n;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        if(n == 1)
            return quantities[0];
        if(m == 1)
            return quantities[0]%n? quantities[0]/n + 1 : quantities[0]/n;
        
        int low = 0, high = 0, ans = INT_MAX;
        for(int i: quantities){
            high = max(high, i);
        }
        
        while(low<=high){
            int mid = low + (high - low)/2;
            if(isValid(quantities, n, mid)){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        
        return ans;
    }
};