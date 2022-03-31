class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int ans = 1, streak = 0;
        int i = 0,j = 0;
        unordered_set<char> ss;
        while(j<n){
            streak++;
            char c = s.at(j);
            auto it = ss.find(c); 
            if(it != ss.end()){
                while(s.at(i) != c || s.at(i) == c){
                    streak--;
                    ss.erase(ss.find(s.at(i)));
                    i++;
                    if(s.at(i-1) == c) break;
                }
            }
            ss.insert(c);
            j++;
            ans = max(ans,streak);
        }
        return ans;
    }
};