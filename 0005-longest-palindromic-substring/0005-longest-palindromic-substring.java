class Solution {
    public String longestPalindrome(String s) {
        if(s.length()<=1)
            return s;
        String ans = "", even, odd;
        for(int i = 0; i<s.length(); i++){
            even = palindromeFromCenter(s, i, i);
            if(even.length()>ans.length())
                ans = even;
            if(i<s.length()-1 && s.charAt(i) == s.charAt(i+1)){
                odd = palindromeFromCenter(s, i, i+1);
                if(odd.length()>ans.length())
                    ans = odd;
            }
        }
        return ans;
        
    }
    private String palindromeFromCenter(String s, int left, int right){
        while(left>=0 && right<s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        return s.substring(left+1, right);
    }
}