class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, k=0;
        string ans = word1+word2;
        while(i<word1.length() && j<word2.length()){
            ans[k++] = word1[i++];
            ans[k++] = word2[j++];
        }
        while(i<word1.length()){
            ans[k++] = word1[i++];
        }
        while(j<word2.length()){
            ans[k++] = word2[j++];
        }
        return ans;
    }
};