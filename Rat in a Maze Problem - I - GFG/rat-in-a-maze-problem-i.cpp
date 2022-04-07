// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++


class Solution{
    public:
    void solve(vector<vector<int>> &m, int n, vector<string>& ans, int i, string &s, int j){
        if(i==n || j==n || i<0 || j<0) return;
        if(i == n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        for(int k = 0; k<4; k++){
            switch(k){
            case 0: if(j+1<n && m[i][j+1] == 1){
                        s += 'R';
                        m[i][j] = 0;
                        solve(m, n, ans, i, s, j+1);
                        m[i][j] = 1;
                        s.pop_back();
                    }
                    break;
            case 1: if(i+1<n && m[i+1][j] == 1){
                        s += 'D';
                        m[i][j] = 0;
                        solve(m, n, ans, i+1, s, j);
                        m[i][j] = 1;
                        s.pop_back();
                    }
                    break;
            case 2: if(j-1>=0 && m[i][j-1] == 1){
                        s += 'L';
                        m[i][j] = 0;
                        solve(m, n, ans, i, s, j-1);
                        m[i][j] = 1;
                        s.pop_back();
                    }
                    break;
            case 3: if(i-1>=0 && m[i-1][j] == 1){
                        s += 'U';
                        m[i][j] = 0;
                        solve(m, n, ans, i-1, s, j);
                        m[i][j] = 1;
                        s.pop_back();
                    }
                    break;
            }
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[n-1][n-1] == 0 || m[0][0] == 0) return ans;
        string s = "";
        solve(m, n, ans, 0, s, 0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends