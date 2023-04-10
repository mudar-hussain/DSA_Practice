class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(st.empty()){
                if(c == '}' || c==']' || c==')')
                    return false;
                else
                    st.push(c);
            }
            else if((c == '}' && st.top() == '{') || 
                    (c==']' && st.top()== '[') || 
                    (c==')' && st.top()== '(')){
                st.pop();
            }else
                st.push(c);
        }
        return st.empty();
    }
};