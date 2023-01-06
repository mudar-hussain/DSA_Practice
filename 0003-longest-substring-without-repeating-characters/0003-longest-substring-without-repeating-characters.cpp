class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int count = 1;
        unordered_set<char> st;
        int i = 0, j = 0;
        while(j<s.length()){
            if(st.find(s[j]) != st.end()){
                count = max(count, j-i);
                while(s[i]!=s[j]){
                    st.erase(s[i++]);
                }
                i++;
            }else{
                st.insert(s[j]);
            }
            j++;
        }
        count = max(count, j-i);
        return count;
    }
};