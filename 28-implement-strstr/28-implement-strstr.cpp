#include <string.h>
class Solution {
    
        
public:
    //2nd Approach
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();
        
        if(n2 == 0) return 0;
        if(n1<n2) return -1;
        
        for(int i = 0; i<n1; i++){
            if(haystack[i] == needle[0]){
                int x = i, y = 0;
                while(x<n1 && y<n2){
                    if(haystack[x] != needle[y]) break;
                    x++;
                    y++;
                }
                if(y == n2) return i;
            }
        }
        return -1;
    }
    
    
    
    //1st Approach
//     int strStr(string haystack, string needle) {
        
//         if(needle.length() == 0) return 0;
//         return haystack.find(needle);
//     }
};