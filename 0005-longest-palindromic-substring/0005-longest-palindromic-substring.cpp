class Solution {
public:
    
    string findPalindrome(string &s, int &n, int i, int j){
        if(i<0 || j>= n || s[i] != s[j]){
            return s.substr(i+1, j-1-i);
        }
        
        return findPalindrome(s, n, i-1, j+1);
    }
    
    
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return "";
        int n = s.length();
        string ans = s.substr(0,1);
        int maxi = 1;
        string temp = "";
        for(int i = 1; i<s.length(); i++){
            //even
            if(s[i] == s[i-1]){
                temp = findPalindrome(s, n, i-1, i);
                if(temp.length()>maxi){
                    ans = temp;
                    maxi = ans.length();
                }
            }
            //odd
            if(i+1<=n-1 && s[i-1] == s[i+1]){
                temp = findPalindrome(s, n, i-1, i+1);
                if(temp.length()>maxi){
                    ans = temp;
                    maxi = ans.length();
                }
            }
        }
        return ans;
        
    }
};