class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> um;
        for(char c: stones){
            um[c]++;
        }
        int ans = 0;
        for(char c: jewels)
            ans += um[c];
        return ans;
    }
};