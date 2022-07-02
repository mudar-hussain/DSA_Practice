class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        unordered_set<char> st;
        while(i<=j && j<n){
            auto it = st.find(s[j]);
            if(it != st.end()){
                ans = max(ans, j-i);
                while(s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            st.insert(s[j]);
            j++;
            ans = max(ans, j-i);
        }
        return ans;
    }
};