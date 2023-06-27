class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> ans;
        int sum;
        for(int i: nums1){
            for(int j: nums2){
                sum = i+j;
                if(pq.size()<k){
                    pq.push({sum, {i,j}});
                }
                else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum, {i,j}});
                }else
                    break;
            }
        }
        
        //sort(v.begin(), v.end(), myCmp);
        
        while(!pq.empty()){
            
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        
        return ans;
        
    }
};