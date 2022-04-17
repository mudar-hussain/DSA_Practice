class Solution {
public:
    //2nd Approach ((Time: O(1); Space: O(1)))
    string reverseWords(string s) {
        int n = s.length();
        if(n==1) return s;
        string str = "";
        for(int i = n-1; i>=0; i--){
            if(s[i] == ' ') continue;
            int j = i;
            while(j>=0 && s[j] != ' '){
                j--;
            }
            j++;
            s += s.substr(j, i-j+1) + " ";
            i = j;
        }
        
        s.pop_back();
        
        return s.substr(n,s.length()-1);
    }
    
    
    //1st Approach(Time: O(1); Space: O(n))
//     string reverseWords(string s) {
//         int n = s.length();
//         vector<string> v;
//         for(int i = 0; i<n; ){
//             int j = i;
//             while(j<n && s[j] != ' '){
//                 j++;
//             }
//             if(j!=i) 
//                 v.push_back(s.substr(i, j-i));
//             if(j == n-1) break;
//             i = j+1;
//         }
//         s = "";
//         for(int i = v.size()-1; i>=0; i--){
//             s += v[i];
//             if(i!=0) s += " ";
//         }
        
//         return s;
//     }
};