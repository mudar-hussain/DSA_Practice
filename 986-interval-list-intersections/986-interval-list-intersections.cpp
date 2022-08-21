class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        int start, end;
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            start = max(firstList[i][0], secondList[j][0]);
            end = min(firstList[i][1], secondList[j][1]);
            
            if(start<=end)
                ans.push_back({start, end});
            
            if(firstList[i][1] < secondList[j][1])  i++;
            else j++;
        }
        return ans;
    }
};