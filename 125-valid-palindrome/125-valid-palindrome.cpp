class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.length()-1;
        
        while(low<high){
            if(!isdigit(tolower(s[low])) && (tolower(s[low]) < 97 || tolower(s[low]) > 122)){
                low++;
                continue;
            }
            if(!isdigit(tolower(s[high])) && (tolower(s[high]) < 97 || tolower(s[high]) > 122)){
                high--;
                continue;
            }
            if(tolower(s[low]) != tolower(s[high]))
                return false;
            low++;
            high--;
            
        }
        return true;
    }
};