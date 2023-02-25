//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    unordered_set<int> st;
	    for(int i = 0; i<n; i++){
	        for(auto s: st){
	            if(st.find(s + arr[i]*arr[i]) != st.end() || st.find(abs(s - arr[i]*arr[i])) != st.end())
	                return true;
	        }
	        st.insert(arr[i]*arr[i]);
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends