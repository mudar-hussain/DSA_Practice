class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        char map[26];
        for(int i = 0; i<26; i++){
            map[i] = i + 'a';
        }
        for(int i = 0; i<n; i++){
            int replace = max(map[s1[i]-'a'], map[s2[i]-'a']);
            int put = min(map[s1[i]-'a'], map[s2[i]-'a']);
            
            for(int i = 0; i<26; i++){
                if(map[i] == replace)
                    map[i] = put;
            }
        }
        for(int i = 0; i<baseStr.length(); i++){
            baseStr[i] = map[baseStr[i]-'a'];
        }
        return baseStr;
    }
};