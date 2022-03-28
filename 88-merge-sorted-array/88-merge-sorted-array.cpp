class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0, j = 0; j<n;i++){
            if(nums2[j]<=nums1[i] || i>=m){
                nums1.insert(nums1.begin()+i,nums2[j]);
                nums1.pop_back();
                j++;m++;
            }
        }
        
    }
};