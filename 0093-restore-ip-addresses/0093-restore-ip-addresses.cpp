class Solution {
public:
    void solve(string &s, vector<string> &ans, string temp, int dots, int idx){
        if(idx == s.length() && dots == 4){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        if(idx >= s.length() && dots != 4){
            return;
        }
        int value = 0;
//         if(dots == 4){
//             for(int i = idx; i<s.length(); i++){
//                 value *= 10+(s[i]-'0');
//                 temp += s[i];
//             }
//             if(value<=255){
//                 ans.push_back(temp);
//                 return;
//             }
                
//         }
        if(dots>4)
            return;
        for(int i = idx; i<s.length() && i<idx+3 && dots<5; i++){
            value = (value*10)+(s[i]-'0');
            if(value == 0){
                temp.push_back(s[i]);
                temp.push_back('.');
                solve(s, ans, temp, dots+1, i+1);
                break;
            }
            if(value<=255){
                temp.push_back(s[i]);
                temp.push_back('.');
                solve(s, ans, temp, dots+1, i+1);
                temp.pop_back();
                
            }else 
                break;
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp = "";
        solve(s, ans, temp, 0, 0);
        return ans;
    }
};