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
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(um[s[i+1]]<=um[s[i]])
                ans += um[s[i]];
            else 
                ans -= um[s[i]];
        }
        return ans;
    }
};