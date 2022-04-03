class Solution {
public:
    //3rd Approach
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int prefix[n], postfix[n];
        
        prefix[0] = height[0];
        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        
        postfix[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            postfix[i] = max(postfix[i+1], height[i]);
        }
        
        for(int i = 1; i<n-1; i++){
            ans += min(postfix[i], prefix[i])-height[i];
        }
        return ans;
        
    }
    
    
    //2nd Approach
//     int trap(vector<int>& height) {
//         int ans = 0;
//         int n = height.size();
        
//         for(int i = 1; i<n; i++){
//             int rmx = 0, lmx = 0;
//             int j = i;
//             while(j>=0){
//                 lmx = max(lmx, height[j]);
//                 j--;
//             }
//             j = i;
//             while(j<n){
//                 rmx = max(rmx, height[j]);
//                 j++;
//             }
//             ans += min(lmx, rmx)-height[i];
//         }
//         return ans;
        
//     }
    //1st Approach
//     int trap(vector<int>& height) {
//         int n = height.size();
        
//         int res=0;
        
//         int left=0, right=n-1;
        
//         int left_max=0, right_max=0;
        
//         while(left<right){
//             if(height[left]<height[right]){
//                 left_max = max(left_max, height[left]);
//                 res+=left_max-height[left];
//                 left++;
//             }else{
//                 right_max = max(right_max, height[right]);
//                 res+=right_max-height[right];
//                 right--;
//             }
//         }
        
//         return res;
        
//     }
};