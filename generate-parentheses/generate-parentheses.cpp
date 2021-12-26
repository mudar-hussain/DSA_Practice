class Solution {
    private:
    vector<string> ans;
public:
    void solve(string op, int o, int c){
        if(o == 0 && c==0){
            ans.push_back(op);
            return;
        }
        if(o==c){
            op.append("(");
            solve(op,o-1,c);
        }else if(o<c && o!=0){
            string op1 = op+"(";
            string op2 = op+")";
            solve(op1,o-1,c);
            solve(op2,o,c-1);
        }else if(c!=0){
            op.append(")");
            solve(op,o,c-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string op;
        solve(op,n,n);
        return ans;
    }
};