class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> um= {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};
        
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