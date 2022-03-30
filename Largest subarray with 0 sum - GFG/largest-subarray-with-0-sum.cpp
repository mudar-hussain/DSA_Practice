// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>& nums, int n)
    {   
        // Your code here
        int ans = 0, sum = 0;
        unordered_map<int,int> hm;
        hm[0] = -1;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            auto it = hm.find(sum);
            if(it != hm.end()){
                ans = max(ans, i-(it->second));
            }
            else hm[sum] = i;
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends