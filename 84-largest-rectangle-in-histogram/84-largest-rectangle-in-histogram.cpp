class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = INT_MIN;
        vector<int> left(n+1,0);
        stack<int> st_l;
        st_l.push(-1);
        
        for(int i= 0; i<n; i++){
            while(st_l.top() != -1 && heights[st_l.top()] >= heights[i])   st_l.pop();
            
            left[i] = st_l.top();
            st_l.push(i);
        }
        
        vector<int> right(n+1,0);
        stack<int> st_r;
        st_r.push(n);
        
        for(int i = n-1; i>=0; i--){
            while(st_r.top() != n && heights[st_r.top()] >= heights[i])   st_r.pop();
            
            right[i] = st_r.top();
            st_r.push(i);
        }
        
        for(int i = 0; i<n; i++){
            ans = max(ans, heights[i]*(right[i]-left[i]-1));
        }
        
        return ans;
        
    }
};