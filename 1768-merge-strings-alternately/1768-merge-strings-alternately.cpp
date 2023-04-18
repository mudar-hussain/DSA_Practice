class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        int m = word1.length(), n = word2.length();
        string ans = "";
        while(i<m && j<n){
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        if(i<m){
            ans.append(word1,i);
        }
        else if(j<n){
            ans.append(word2, j);
        }
        return ans;
    }
};