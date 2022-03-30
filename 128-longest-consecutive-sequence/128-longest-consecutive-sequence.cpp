class Solution {
public:
    //2nd Approach
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> mp;
        for(auto i: nums)
            mp.insert(i);
        int ans = 1,curr,prev;
        for(int i = 0; i<n; i++){
            curr = 1;
            if(mp.find(nums[i]-1) == mp.end()){
                prev = nums[i]+1;
                while(mp.find(prev) != mp.end()){
                    curr++;
                    prev++;
                }
                ans = max(ans,curr);
            }
        }
        return ans;
    }
    //1st Approach
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n==0) return 0;
//         sort(nums.begin(), nums.end());
//         int i = 1;
//         int ans = 1,prev = nums[0],curr = 1;
//         while(i<n){
//             if(nums[i] == prev+1){
//                 curr++;
//             }
//             else if(nums[i] != prev){
//                 curr = 1;
//             }
//             prev = nums[i];
//             ans = max(ans, curr);
            
//             i++;
//         }
//         return ans;
//     }
};