class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> um;
        for(int i = 0; i<n2-1; i++){
            int j = i+1;
            for( j = i+1; j<n2; j++){
                if(nums2[i]<nums2[j]) {
                    um.insert({nums2[i],nums2[j]});
                    break;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<n1; i++){
            if(um[nums1[i]] == 0) ans.push_back(-1);
            else ans.push_back(um[nums1[i]]);
        }
        return ans;
    }
};