class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> um;
        
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        
        int ans = um[s[n-1]];
        int curr, prev = ans;
        for(int i = n-2; i>=0; i--){
            curr = um[s[i]];
            if(curr>=prev) ans += curr;
            else ans -= curr;
            prev = curr;
        }
        return ans;
    }
};