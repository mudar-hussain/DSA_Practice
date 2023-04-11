class Solution {
public:
    string removeStars(string s) {
        int i = 0;
        for(int j = 0; j<s.length(); j++){
            s[i++] = s[j];
            if(i>=2 && s[i-1] == '*'){
                i -= 2;
            }
        }
        return s.substr(0,i);
    }
};