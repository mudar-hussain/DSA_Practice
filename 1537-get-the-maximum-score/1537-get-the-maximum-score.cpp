class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        
        while(i<n && j<m){
            if(nums1[i]<nums2[j])
                sum1+= nums1[i++];
            else if(nums1[i]>nums2[j])
                sum2 += nums2[j++];
            else{
                sum1 = max(sum1, sum2) + nums1[i];
                sum2 = sum1;
                i++; j++;
            }
        }
        while(i<n)
            sum1 += nums1[i++];
        while(j<m)
            sum2 += nums2[j++];
        
        return max(sum1, sum2)%1000000007;
    }
};