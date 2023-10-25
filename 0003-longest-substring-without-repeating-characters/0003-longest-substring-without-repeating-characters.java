class Solution {
    public int lengthOfLongestSubstring(String s) {
        int longestSubstring = 0;
        int i = 0, j = 0;
        Set<Character> st = new HashSet<>();
        while(j<s.length()){
            if(st.contains(s.charAt(j))){
                while(st.contains(s.charAt(j))){
                    st.remove(s.charAt(i));
                    i++;
                }
            }
            st.add(s.charAt(j));
            j++;
        
            longestSubstring = Math.max(longestSubstring, st.size());
        }
        return longestSubstring;
    }
}