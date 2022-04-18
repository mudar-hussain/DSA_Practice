#include <string.h>
class Solution {
    
        
public:
    //3rd Approach
    inline int getHash(char ch) {
        return ch - 'a' + 1;
    }
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;
        int hash = 0, rollingHash = 0;
        for (char ch: needle) hash += getHash(ch);
        for (int i = 0; i < needle.length(); i++) {
            rollingHash += getHash(haystack[i]);
        }
        if (rollingHash == hash) {
            bool match = true;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return 0;
        }
        for (int i = 1; i <= haystack.length() - needle.length(); i++) {
            rollingHash += getHash(haystack[i + needle.length() - 1]) - getHash(haystack[i - 1]);
            if (rollingHash == hash) {
                bool match = true;
                for (int j = 0; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return i;
            }
        }
        return -1;
    }
    
    //2nd Approach
//     int strStr(string haystack, string needle) {
//         int n1 = haystack.length();
//         int n2 = needle.length();
        
//         if(n2 == 0) return 0;
//         if(n1<n2) return -1;
        
//         for(int i = 0; i<n1; i++){
//             if(haystack[i] == needle[0]){
//                 int x = i, y = 0;
//                 while(x<n1 && y<n2){
//                     if(haystack[x] != needle[y]) break;
//                     x++;
//                     y++;
//                 }
//                 if(y == n2) return i;
//             }
//         }
//         return -1;
//     }
    
    
    
    //1st Approach
//     int strStr(string haystack, string needle) {
        
//         if(needle.length() == 0) return 0;
//         return haystack.find(needle);
//     }
};