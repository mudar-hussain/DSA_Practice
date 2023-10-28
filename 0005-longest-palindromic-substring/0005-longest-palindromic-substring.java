class Solution {
    public String longestPalindrome(String s) {
        if(s.length()<=1)
            return s;
        String ans = s.substring(0,1);
        String temp = "";
        for(int i = 1; i<s.length(); i++){
            //even
            if(s.charAt(i)==(s.charAt(i-1))){
                temp = findPalindrome(s, i-1, i);
                if(temp.length()>ans.length()){
                    ans = temp;
                }
            }
            //odd
            if(i+1 < s.length() && s.charAt(i-1)==(s.charAt(i+1))){
                temp = findPalindrome(s, i-1, i+1);
                if(temp.length()>ans.length()){
                    ans = temp;
                }
            }
        }
        return ans;
    }
    private String findPalindrome(String s, int l, int r){
        if(l<0 || r>=s.length() || s.charAt(l) != (s.charAt(r))){
            return s.substring(l+1, r);
        }
        return findPalindrome(s, l-1, r+1);
    }
}