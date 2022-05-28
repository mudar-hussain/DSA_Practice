class Solution {
public:
    void fill(vector<vector<char>> &dict){
        dict[2] = {'a', 'b', 'c'};
        dict[3] = {'d', 'e', 'f'};
        dict[4] = {'g', 'h', 'i'};
        dict[5] = {'j', 'k', 'l'};
        dict[6] = {'m', 'n', 'o'};
        dict[7] = {'p', 'q', 'r', 's'};
        dict[8] = {'t', 'u', 'v'};
        dict[9] = {'w', 'x', 'y', 'z'};
        
    }
    
    
    void bt(vector<vector<char>> &dict, string &digits, int k, vector<string> &ans, string curr_string){
        if(k >= digits.size()){
            ans.push_back(curr_string);
            return;
        }
        
        int val = digits[k]-'0';
        for(int i = 0; i<dict[val].size(); i++){
            bt(dict, digits, k+1, ans, curr_string+dict[val][i]);
        }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(n == 0) return ans;
        vector<vector<char>> dict(10, vector<char>(4));
        fill(dict);
        
        int val = digits[0] - 0;
        
        string st = "";
        bt(dict, digits, 0, ans, st);
        return ans;
        
    }
};