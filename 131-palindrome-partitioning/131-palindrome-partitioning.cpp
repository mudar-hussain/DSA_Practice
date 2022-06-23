class Solution {
public:
    bool isPalindrome(string &s, int st, int e){
        while(st<e){
            if(s[st++] != s[e--])
                return false;
        }
        return true;
    }
    void solve(string &s, vector<vector<string>> &ans, vector<string> &temp, int start){
        if(start == s.length()){
            ans.push_back(temp);
            return;
        }
        string ss = "";
        for(int i = start; i<s.length(); i++){
            ss.push_back(s[i]);
            if(isPalindrome(s, start, i)){
                temp.push_back(ss);
                solve(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, ans, temp, 0);
        return ans;
    }
};