class Solution {
public:
    bool func(string pattern, string leftover){
        int n=leftover.length();
        int i=0;
        while(i!=n){
            if(pattern[i%pattern.length()]!= leftover[i])
                return false;
            i++;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        string str="";
        int n=s.length();
        
        for(int i=0;i<n/2;i++){
        str+=s[i];
            if(n%str.length()==0){
            bool x=func(str,s.substr(i+1));
            if(x) return true;
        }
            }
        return false;
    }
};