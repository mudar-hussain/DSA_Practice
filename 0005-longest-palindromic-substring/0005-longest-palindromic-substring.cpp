class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
        
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string longestPalindrome = "";
        for(int i = 0; i<n && (n-i)>(longestPalindrome.length()); i++){
            for(int j = n-1; j>=i; j--){
                if(isPalindrome(s, i, j)){
                    if(longestPalindrome.length() < j-i+1)
                        longestPalindrome = s.substr(i, j-i+1);
                    break;
                }
                    
            }
        }
        return longestPalindrome;
    }
};