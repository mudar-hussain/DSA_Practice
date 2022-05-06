class Solution {
public:
    //2nd Approach (Optimum)
    
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ans = 0;
        
        while(right < nums.size()) {
            mp[nums[right]]++;
            while(mp.size() > k) {
                if(--mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            ans += (right - left + 1);
            right++;
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
    
    //1st Approach (Worst TC)
    // int subarraysWithKDistinct(vector<int>& nums, int k) {
    //     int ans = 0;
    //     int sz = k;
    //     while(sz<=nums.size()){
    //         int unique = 0;
    //         map<int,int> mp;
    //         int i = 0;
    //         int j = 0;
    //         while(j<nums.size()){
    //             while(j-i+1 <= sz){
    //                 if(mp[nums[j]] == 0) 
    //                     unique++;
    //                 mp[nums[j]]++;
    //                 j++;
    //             }
    //             j--;
    //             if(j-i+1 == sz){
    //                 if(unique == k)
    //                     ans++;
    //                 mp[nums[i]]--;
    //                 if(mp[nums[i]] == 0)
    //                     unique--;
    //                 i++;
    //                 j++;
    //             }
    //         }
    //         sz++;
    //     }
    //     return ans;
    // }
};