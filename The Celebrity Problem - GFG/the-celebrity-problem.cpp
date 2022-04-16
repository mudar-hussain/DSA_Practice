// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& nums, int n) 
    {
        // code here 
        int ans = -1;
        int m = nums[0].size();
        for(int i = 0;i<n;i++){
            if(find(nums[i].begin(), nums[i].end(), 1) == nums[i].end()){
                int j = i;
                bool flag = true;
                for(int k = 0; k<n; k++){
                    if(nums[k][j] == 1 && k==i){
                        flag = false;
                        break;
                    } 
                    else if(nums[k][j] == 0 && k==i){
                        ans = i;
                    }else if(nums[k][j] == 0 && k!=i){
                        flag = false;
                        break;
                    }
                }
                if(flag) return ans;
                else ans = -1;
            }
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends