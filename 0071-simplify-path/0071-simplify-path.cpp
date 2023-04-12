class Solution {
public:
    string simplifyPath(string path) {
        if(path.length() == 0)
            return "/";
        if(path[0] != '/')
            path = "/" + path;
        string ans = "";
        string curr = "";
        stack<string> st;
        for(int i = 0; i<path.length(); i++){
            
            if(path[i] == '/'){
                if(curr.length() && curr != "."){
                    if(curr == ".." && !st.empty())
                        st.pop();
                    else if(curr != "..")
                        st.push(curr);
                }
                curr = "";
            }else 
                curr = curr + path[i];
        }
        
        if(curr.length()){
            if(curr.length() && curr != "."){
                    if(curr == ".." && !st.empty())
                        st.pop();
                    else if(curr != "..")
                        st.push(curr);
                }
        }
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.length() == 0)
            return "/";
        
        return ans;
    }
};