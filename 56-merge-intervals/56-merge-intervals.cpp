class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        
        for(int i = 1; i<n; i++){
            if(intervals[i][0]>end){
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
                
            }else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});
        
        
//         int i,j, temp;
//         for( i = 0, j=1; i<n; i++, j++){
//             if(j<n && intervals[i][1]>=intervals[j][0]){
//                 temp = min(intervals[i][0],intervals[j][0]);
//                 for(;j<n && intervals[i][1]>=intervals[j][0]; i++,j++){
//                     temp = min(min(temp,intervals[i][0]),intervals[j][0]);
//                 };
//                 ans.push_back({temp,intervals[i][1]});
//             }
            
//             else{
//                 ans.push_back(intervals[i]);
//             }
//         }
        return ans;
    }
};