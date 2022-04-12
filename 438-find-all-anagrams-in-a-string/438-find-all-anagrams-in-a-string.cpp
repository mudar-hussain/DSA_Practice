class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
	    int win = p.length();
	    vector<int> ans;
        unordered_map<char,int> um;
        for(int i = 0; i<win; i++) {
            if(um.find(p[i]) == um.end()){
                um.insert(make_pair(p[i],1));
            }else
                um[p[i]]++;
        }
	    int i = 0, j = 0;
        int count = um.size();
	    while(j<n){
            if(um.find(s[j]) != um.end()){
                um[s[j]]--;
                if(um[s[j]] == 0) count--;
            } 
            if(j-i+1 == win){
                if(count == 0) ans.push_back(i);
                if(um.find(s[i]) != um.end()){
                    um[s[i]]++;
                    if(um[s[i]] == 1) count++;
                }
                i++;
            }
            j++;
	    }
        return ans;
    }
};