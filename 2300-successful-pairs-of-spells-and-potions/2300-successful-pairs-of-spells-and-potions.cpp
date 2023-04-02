class Solution {
    int findIndex(vector<int> &potions, long long sp, long long success){
        int low = 0, high = potions.size()-1;
        int mid, ans = INT_MAX;
        while(low<=high){
            mid = low + (high-low)/2;
            if((long long)(sp*potions[mid]) >= success){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(ans == INT_MAX)
            return potions.size();
        else
            return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        int lastZero = -1;
        for(int sp: spells){
            if(lastZero != -1 && sp<=lastZero){
                ans.push_back(0);
                continue;
            }
            // for(int i = 0; i<n; i++){
            //     if(((long long)potions[i] >= success) 
            //        || ((long long)sp >= success) 
            //        || ((long long)sp*potions[i] >= success)){
            //         ans.push_back(n-i);
            //         break;
            //     }
            //     if(i == n-1){
            //         ans.push_back(0);
            //         lastZero = sp;
            //     }
            // }
            
            int idx = findIndex(potions, sp, success);
            ans.push_back(n-idx);
            if(idx == n){
                lastZero = sp;
            }
        }
        return ans;
    }
};