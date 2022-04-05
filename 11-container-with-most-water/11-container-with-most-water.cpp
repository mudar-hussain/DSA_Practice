class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = -1,i = 0, j= n-1;
        while(i<j){
            ans = max(ans, min(height[i],height[j])*abs(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};