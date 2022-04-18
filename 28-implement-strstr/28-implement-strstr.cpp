#include <string.h>
class Solution {
    
        
public:
    //3rd Approach
    int strStr(string haystack, string needle) {
        long long ha=0, hb=0;
        for (int i = 0; i < needle.size(); i++){
            hb = hb + (needle[i] - 'A' + 1);
        }
        int l=0, r = 0;
        while (r < haystack.size()){
            ha = ha + (haystack[r] - 'A' + 1);
            if(r-l+1==needle.size()){
                if(ha==hb){
                    int i = l;
                    bool match = true;
                    for(auto x: needle){
                        if(x != haystack[i])
                            match = false;
                        i++;
                    }
                    if(match) return l;
                }
                        
                ha = ha - (haystack[l] - 'A' + 1);
                l++;
            }
        r++;
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