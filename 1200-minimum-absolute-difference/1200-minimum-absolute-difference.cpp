class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int mindiff = arr[1] - arr[0];
        
        for(int i = 1; i<n; i++){
            if(arr[i]-arr[i-1]<mindiff){
                ans.clear();
                mindiff = arr[i]-arr[i-1];
            }
            if(arr[i]-arr[i-1] == mindiff)
                ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
        
    }
};