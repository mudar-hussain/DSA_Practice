// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
int result[2];
    int *findTwoElement(int *arr, int n) {
        // code here
        // int n = A.size();
        
    int track[n+1] = {0};
    for(int i = 0; i<n; i++){
        track[arr[i]]++;
    }
    
    int r,m;
    for(int i = 1; i<=n; i++){
        if(track[i] == 2) r = i;
        if(track[i] == 0) m = i;
    }
    result[0] = r;
    result[1] = m;
    return result;
        // int sum = (n*(n+1))/2;
        // int sumSq = (n*(n+1)*(2*n+1))/6;
        // for(int i = 0; i<n; i++){
        //     sum -= arr[i];
        //     sumSq -= arr[i]*arr[i];
        // }
        // result[1] = (sum+(sumSq/sum))/2;
        // result[0] = result[1] - sum;
        // return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends