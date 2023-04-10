class Solution {
    unordered_map<string, int> mp;
    int solve(string s, int cnt, set<string> &st){
        if(cnt == 0){
            if(findRemovalCount(s) == 0){
                st.insert(s);
                return 1;
            }else
                return 0;
        }
        
        if(mp.find(s) != mp.end())
            return mp[s];
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == ')'){
                string left = s.substr(0, i);
                string right = s.substr(i+1);
                mp[left+right] = solve(left+right, cnt-1, st);
            }
        }
        
        return mp[s];
    }
    
    
    int findRemovalCount(string s){
        stack<char> st;
        for(char c: s){
            if(c == '(')
                st.push(c);
            else if(c == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else 
                    st.push(c);
            }
        }
        return st.size();
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int removalCount = findRemovalCount(s);
        set<string> st;
        solve(s, removalCount, st);
        vector<string> ans;
        for(auto i: st){
            ans.push_back(i);
        }
        return ans;
    }
};