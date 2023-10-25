class Solution {
    public int lengthOfLongestSubstring(String s) {
        int longestSubstring = 0;
        int i = 0, j = 0;
        int[] chars = new int[256];
        Arrays.fill(chars, -1);
        while(j<s.length()){
            if(chars[s.charAt(j)] == 1){
                while(i<j && chars[s.charAt(j)] == 1){
                    chars[s.charAt(i)] = -1;
                    i++;
                }
            }
            chars[s.charAt(j)] = 1;
            j++;
        
            longestSubstring = Math.max(longestSubstring, j-i);
        }
        return longestSubstring;
    }
}