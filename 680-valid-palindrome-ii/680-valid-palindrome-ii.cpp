class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s.at(l) != s.at(r)) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(s.at(l) != s.at(r)){
                return isPalindrome(s, l, r-1) || isPalindrome(s, l+1, r);
            }
            l++;
            r--;
        }
        return true;
    }
};