class Solution {
public:
    bool isValid(string s) {
        int last;
        while(s.length()){
            last = s.length();
            for(int i = 0; i+2<s.length(); i++){
                if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c'){
                    if(i+3<s.length()){
                        s = s.substr(0, i) + s.substr(i+3);
                    }else
                        s = s.substr(0, i);
                    i--;
                }  
            }
            
            if(last == s.length())
                break;
        }
        return s.length()==0;
    }
};