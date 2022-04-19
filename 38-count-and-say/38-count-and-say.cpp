class Solution {
public:
    
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n-1);
        int count = 0;
        string ans = "";
        for(int i = 0; i<prev.length(); i++){
            if(i != 0 && (prev[i]!=prev[i-1])){
                ans += to_string(count) + prev[i-1];
                count = 0;
            }
            count++;
        }
        ans += to_string(count) + prev[prev.length()-1];
         return ans;
    }
};