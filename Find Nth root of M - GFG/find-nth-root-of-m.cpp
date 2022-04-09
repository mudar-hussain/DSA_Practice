// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    long low = 1, high = m;
	    while(low<=high){
	        long val = 1;
	        long mid = low+(high-low)/2;
	        for(int i = 1; i<=n; i++){
	            val *= mid;
	            if(val > m) break;
	        }
	        if(val == m) return mid;
	        else if(val>m) high = mid-1;
	        else low = mid+1;
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends