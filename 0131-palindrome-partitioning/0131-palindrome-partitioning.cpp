class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        DFS(s, 0, curr, result);
        
        return result;
    }
    void DFS(const string& s, int start, vector<string>& curr, vector<vector<string>>& result) {
        if (s.size() == start) {
           result.push_back(curr);
           return;
        }

        for (int i = start; i < s.size(); i++) {
            if (IsPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                DFS(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
        return;
    }
    bool IsPalindrome(const string& s, int a, int b) {
        while (a < b) {
            if (s[a] != s[b]) {
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
};