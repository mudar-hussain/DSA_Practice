class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        for(char c: s){
            s[i++] = c;
            if(i>=3 && s[i - 3] == 'a' && s[i - 2] == 'b' && s[i - 1] == 'c'){
                i -= 3;
            }
        }
        return i == 0;
    }
};