class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX;
        for(int i: nums){
            if(i%2){
                pq.push(i*2);
                mini = min(mini, i*2);
            }else{
                pq.push(i);
                mini = min(mini, i);
            }
        }
        
        int ans = INT_MAX;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            ans = min(ans, temp-mini);
            if(temp%2 != 0) break;
            
            mini = min(mini, temp/2);
            pq.push(temp/2);
        }
        return ans;
        
    }
};