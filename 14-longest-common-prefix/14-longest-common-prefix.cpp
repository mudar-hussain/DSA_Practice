class Solution {
public:
    //2nd Approach
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i = 0; i<n; i++){
            if(ans.length()<strs[i].length())
                ans = strs[i];
        }
        for(int i = 0; i<n; i++){
            if(ans == "") return "";
            string s2 = strs[i];
            int j = 0;
            for(; j<ans.length() && j<s2.length(); j++){
                if(ans[j] != s2[j]) {
                    if(j == 0) 
                        return "";
                    else
                        ans = ans.substr(0,j);
                    break;
                    
                }
            }
            if(j==s2.length()) ans = s2;
        }
        return ans;
    }
    
    //1st Approach
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.size() == 1) 
//         return strs[0];
// // assign ans with the shortest string in strs
//         string ans = strs[0]; 
//         for(auto ptr1 : strs)
//         {
//             if(ptr1.size()<ans.size())
//                 ans = ptr1;
//         }
		
//         if(ans.size() == 0)
//             return ans;
// // compare ans with all the strings in strs and update ans with common prefix  using the 'substr' function of string
//         for(int i=0; i<strs.size(); i++)
//         {
//             int m = min(strs[i].size(),ans.size()); 
//             for(int j =0; j<m; j++)
//             {
//                 if(strs[i][j] != ans[j])
//                     ans = ans.substr(0,j);
//             }
//         }
//         return ans;
//     }
};