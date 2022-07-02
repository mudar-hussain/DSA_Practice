class Solution {
public:
    // 
    int longestValidParentheses(string s) {
        int n = s.length();
        int max_length = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0;i<n; i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                max_length = max(max_length, i-st.top());
            }
        }
        return max_length;
        
    }
    // Bruteforce
    // int longestValidParentheses(string s) {
    //     int n = s.length();
    //     if(n == 0 || n == 1)
    //         return 0;
    //     int ans = 0;
    //     int count = 0;
    //     stack<char> st;
    //     for(int i = 0; i<n; i++){
    //         if(ans > n-i)
    //             break;
    //         while(!st.empty())  st.pop();
    //         for(int j = i; j<n; j++){
    //             if(s[j] == '('){
    //             st.push(s[j]);
    //         }
    //         if(s[j] == ')'){
    //             if(st.empty()) break;
    //             if(st.top() != '(')
    //                 break;
    //             else
    //                 st.pop();
    //         }
    //         if(st.empty())
    //             ans = max(ans, j-i+1);
    //         } 
    //     }
    //     return ans;
    // }
};