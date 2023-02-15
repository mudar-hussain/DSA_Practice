class Solution {
public:
    vector<int> addToArrayForm(vector<int>& arr, int k) {
        vector<int>ans;
        int i=arr.size()-1;
        int carry=0;
       while(k>0 or i>=0){
           int sum=carry;
           if(i>=0)sum+=arr[i--];
           sum+=k%10;
           carry=sum/10;
           k/=10;
           ans.push_back(sum%10);
       }
       if(carry)ans.push_back(carry);
       reverse(ans.begin(),ans.end());
        return ans;
    }
};