// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int max = INT_MAX;
            int ans = 0;
            for(int i = 0; i<N; i++){
                int index = -1, l = 0, h = M-1;
                while(l<=h){
                    int mid = l + (h-l)/2;
                    if(Mat[i][mid] == 1){
                        index = mid;
                        h = mid-1;
                    }else
                        l = mid+1;
                }
                if(index != -1 && max > index){
                    max = index;
                    ans = i;
                }
            }
            return ans;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends