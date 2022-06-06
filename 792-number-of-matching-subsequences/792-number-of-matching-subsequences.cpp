class Solution {
public:
    int numMatchingSubseq(string p, vector<string>& words) {
        int m = p.size();
        int ans = 0;
        unordered_map<string, int> um;
        for(string s: words)
            um[s]++;
        
        for(auto s: um){
            int n = s.first.size();
        
            if(n == 0 && m == 0){
                ans += s.second;
                continue;
            }
                
            if(n == 0){
                ans += s.second;
                continue;
            }
            if(m == 0){
                continue;
            }


            int j = 0;
            for(int i = 0; i<m; i++){
                if(p[i] == s.first[j]){
                    j++;
                }
                if(j == n){
                    ans += s.second;
                    break;
                }
                    
            }
            
        }
        return ans;
    }
};