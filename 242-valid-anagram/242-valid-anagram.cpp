class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1!=n2) return false;
        int chars[27] = {0};
        for(int i = 0; i<n1; i++){
            chars[s[i] - 'a']++;
        }
        for(int i = 0; i<n2; i++){
            chars[t[i] - 'a']--;
        }
        for(int i = 0; i<27; i++){
            if(chars[i] != 0) 
                return false;
        }
        return true;
    }
};