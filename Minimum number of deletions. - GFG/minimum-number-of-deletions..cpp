// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string str, int n) { 
    //complete the function here 
     int t[1001][1001];
   string temp=str;
   reverse(str.begin(),str.end());
   string sar=str;
   str=temp;
   //int n=str.length();
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
           if(n==0)
           t[i][j]=0;
       }
   }
   int ans=0;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(str[i-1]==sar[j-1])
           t[i][j]=1+t[i-1][j-1];
           else
           t[i][j]=max(t[i-1][j],t[i][j-1]);
           ans=max(ans,t[i][j]);
       }
   }
   return str.length()-ans;
} 