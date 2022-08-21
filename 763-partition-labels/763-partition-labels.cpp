class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<pair<int, int>> intervals;
        set<char> st;
        int start = -1, end = -1;
        for(int i = 0; i<n; i++){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                start = i;
                end = i;
                for(int j = i+1; j<n; j++){
                    if(s[j] == s[start])
                        end = j;
                }
                intervals.push_back({start, end});
            }
        }
        n = intervals.size();
        vector<int> ans;
         start = intervals[0].first;
         end = intervals[0].second;
        for(int i = 1; i<n; i++){
            if(end<intervals[i].first){
                ans.push_back(end-start+1);
                start = intervals[i].first;
                end = intervals[i].second;
            }else{
                start = min(start, intervals[i].first);
                end = max(end, intervals[i].second);
            }
        }
        ans.push_back(end-start+1);
        return ans;
    }
};