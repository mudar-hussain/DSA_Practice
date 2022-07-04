class Solution {
public:
    void solve(vector<string> &ans, string op, int o, int c){
        if(o == 0 && c == 0){
            ans.push_back(op);
            // cout<<op<<endl;
            return;
        }
        if(o == c){
            solve(ans, op+'(', o-1, c);
            return;
        }
        if(o == 0){
            solve(ans, op+')', o, c-1);
            return;
        }
        solve(ans, op+'(', o-1, c);
        solve(ans, op+')', o, c-1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string op;
        solve(ans, op, n, n);
        return ans;
    }
};