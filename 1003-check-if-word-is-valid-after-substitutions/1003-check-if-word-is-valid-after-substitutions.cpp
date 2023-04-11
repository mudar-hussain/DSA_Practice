class Solution {
public:
    bool isValid(string s) {
        char a,b;
        stack<char> st;
        for(char c: s){
            if(c == 'c' && st.size()>=2){
                b = st.top(), st.pop();
                a = st.top(), st.pop();
                if(a == 'a' && b == 'b' && c == 'c'){
                    //Ignore
                }else{
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }else if(c == 'c'){
                return false;
            }else{
                st.push(c);
            }
        }
        return st.empty();
        
    }
};