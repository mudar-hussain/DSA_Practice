class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        int count = 0;
        char curr = ' ';
        for(char c: chars){
            if(c != curr){
                if(count > 1)
                    ans += to_string(count);
                ans += c;
                curr = c;
                count = 0;
            }            
            count++;
        }
        if(count>1)
            ans += to_string(count);
        for(int i = 0; i<ans.length(); i++){
            chars[i] = ans[i];
        }
        return ans.length();
    }
};