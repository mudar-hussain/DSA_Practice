class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int mindiff = INT_MAX;
        for(int i = 0; i<n-1; i++){
            mindiff = min(mindiff, abs(arr[i]-arr[i+1]));
        }
        for(int i = 0; i<n-1; i++){
            if(abs(arr[i]-arr[i+1]) == mindiff)
                ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
        
    }
};