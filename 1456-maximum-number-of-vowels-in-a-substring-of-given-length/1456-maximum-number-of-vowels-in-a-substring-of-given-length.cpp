class Solution {
public:
    int maxVowels(string s, int k) {
        int currVowelCount = 0;
        int maxVowelCount = 0;
        int i = 0, j = 0;
        int n = s.length();
        while(j<n){
            if(s[j] == 'a' 
                  || s[j] == 'e'
                  || s[j] == 'i'
                  || s[j] == 'o'
                  || s[j] == 'u'
                  ){
                    currVowelCount++;
                }
            
            if(j-i+1 < k){
                j++;
              continue;  
            }
            
            maxVowelCount = max(maxVowelCount,currVowelCount);
            if(s[i] == 'a' 
                  || s[i] == 'e'
                  || s[i] == 'i'
                  || s[i] == 'o'
                  || s[i] == 'u'
                  ){
                    currVowelCount--;
                }
            i++;
            j++;
            
        }
        
        return maxVowelCount;
    }
};