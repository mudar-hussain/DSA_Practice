class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        intervals.insert(lower_bound(intervals.begin(), intervals.end(), newInterval), newInterval);
        
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1; i<=n; i++){
            
            if(end < intervals[i][0]){
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});
        
        return ans;
        
        
    }
};












