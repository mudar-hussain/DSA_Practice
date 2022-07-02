class Solution {
public:
    //Approach 2
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = -1, i = 0, j = n-1;
        while(i<j){
            ans = max(ans, min(height[i], height[j])*(j-i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
        
    }
    //Approach 1
    // int maxArea(vector<int>& height) {
    //     int n = height.size();
    //     int ans = 0;
    //     for(int i = 0; i<n; i++){
    //         int cur = 0;
    //         for(int j = i+1; j<n; j++){
    //             cur = max(cur, min(height[i], height[j])*(j-i));
    //         }
    //         ans = max(cur, ans);
    //     }
    //     return ans;
    // }
};