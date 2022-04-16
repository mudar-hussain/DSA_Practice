class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> v;
        for(int i = 0; i<n; ){
            int j = i;
            while(j<n && s[j] != ' '){
                j++;
            }
            if(j!=i) 
                v.push_back(s.substr(i, j-i));
            if(j == n-1) break;
            i = j+1;
        }
        s = "";
        for(int i = v.size()-1; i>=0; i--){
            s += v[i];
            if(i!=0) s += " ";
        }
        
        return s;
    }
};