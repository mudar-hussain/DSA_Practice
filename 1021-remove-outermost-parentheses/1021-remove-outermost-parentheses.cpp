class Solution {
public:
    void solve(string& s, string& ans, int idx, int balance){
        if(idx >= s.length()){
            return;
        }
        if(!((balance == 1 && s[idx] == ')') || (balance == 0 && s[idx] == '(')))
            ans += s[idx];
        
        if(s[idx] == '('){
            balance++;
        }
        else if(s[idx] == ')'){
            balance--;
        }
        
        solve(s, ans, idx+1, balance);
        
    }
    string removeOuterParentheses(string s) {
        string ans = "";
        int n = s.length();
        solve(s, ans, 0, 0);
        return ans;
    }
};