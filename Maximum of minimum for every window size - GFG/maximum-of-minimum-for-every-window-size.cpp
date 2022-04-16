// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//2nd Approach
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        stack<int>st;
    int left[n],right[n];
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
        st.pop();
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    stack<int>s;
    st=s;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
        st.pop();
        right[i]=st.empty()? n:st.top();
        st.push(i);
    }
    
    vector<int>ans(n+1,0);
    for (int i=0; i<n; i++) 
    { 
        int len=right[i]-left[i]-1; 
        ans[len]=max(ans[len],arr[i]); 
    } 
     for (int i=n-1; i>=1; i--) 
        ans[i] = max(ans[i], ans[i+1]);
        
    return vector<int>(ans.begin()+1,ans.end());
        
    }
};
//1st Approach 
// class Solution
// {
//     public:
//     //Function to find maximum of minimums of every window size.
//     int min(int nums[], int n, int k){
        
//         int i = 0, j = 0;
//         int ans = INT_MIN;
        
//         deque<int> dq;
//         while(j<n){
//             while(dq.size()>0 && dq.back() > nums[j]){
//                 dq.pop_back();
//             }
//             dq.push_back(nums[j]);
            
//             if(j-i+1 == k){
//                 ans = max(ans,dq.front());
//                 if(dq.front() == nums[i]) dq.pop_front();
//                 i++;
//             }
//             j++;
//         }
        
        
//         return ans;
//     }
//     vector <int> maxOfMin(int arr[], int n)
//     {
//         // Your code here
//         ios_base::sync_with_stdio(false);
// 	    cin.tie(NULL); cout.tie(NULL);

//         vector<int> ans;
//         if(n == 0) return ans;
//         for(int i = 1; i <= n; i++){
//             ans.push_back(min(arr, n, i));
//         }
//         return ans;
        
//     }
// };

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends