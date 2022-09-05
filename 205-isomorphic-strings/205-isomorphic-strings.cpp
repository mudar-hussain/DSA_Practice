class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char seen[128] = {};
        for (int i = 0; i<s.size(); i++) {
            char c = s[i];
            if (!seen[c]) {
                for (char s: seen) if(s == t[i]) return false;
                seen[c] = t[i];
            }
            else if (seen[c] != t[i]) return false;
        }
        return true;
    }
};