// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int fun(string s);

int main() {
    int tt;
    string s;
    cin >> tt;
    while (tt--) {
        cin >> s;
        cout<<fun(s)<<endl;
        
    }
    return 0;
}// } Driver Code Ends


int fun(string str)
{
    //code here
    set<string> st;
    for(int i = 0; i<str.length()-1; i++){
		    st.insert(str.substr(i,2));
    }
    return st.size();
    
}