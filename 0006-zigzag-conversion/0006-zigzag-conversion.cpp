class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n<=numRows || numRows == 1)
            return s;
        string ans = "";
        for(int i = 0; i<numRows; i++){
            bool flag = true;
            int addUp = i*2;
            int addDown = (numRows - i - 1)*2;
            if(addUp == 0) addUp = addDown;
            if(addDown == 0) addDown = addUp;
            int j = i;
            while(j<n){
                ans.push_back(s[j]);
                
                if(flag){
                    j += addDown;
                }else{
                    j += addUp;
                }
                flag = !flag;
            }
        }
        return ans;
    }
};