class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n-1;
        int ans = 0;
        while(low<high){
            ans = max(ans, (high-low)*min(height[low], height[high]));
            if(height[low]<height[high])
                low++;
            else
                high--;
        }
        
        return ans;
    }
};