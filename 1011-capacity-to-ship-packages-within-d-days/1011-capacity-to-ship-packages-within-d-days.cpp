class Solution {
public:
    bool isValid(vector<int> weights, int days, int limit){
        int sum = 0;
        int cnt = 1;
        for(auto w: weights){
            sum += w;
            if(sum>limit){
                cnt++;
                sum = w;
                if(cnt>days) return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int total_weight = 0;
        int max_weight = INT_MIN;
        for(auto w:weights) {
            total_weight += w;
            max_weight = max(max_weight, w);
        }
        
        int low = max_weight, high = total_weight;
        int ans = -1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isValid(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};