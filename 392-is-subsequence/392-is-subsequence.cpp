class Solution {
public:
    bool isSubsequence(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        if(n == 0 && m == 0)
            return true;
        if(n == 0)
            return true;
        if(m == 0)
            return false;
        
        
        int j = 0;
        for(int i = 0; i<m; i++){
            if(p[i] == s[j]){
                j++;
            }
        }
        if(j == n) 
            return true;
        return false;
    }
};