class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int na = a.length();
        int nb = b.length();
        int ans = 0;
        while(na*ans < nb){
            ans++;
        }
        string s = "";
        for(int i = 0; i<ans; i++){
            s += a;
        }
        cout<<s;
        if(s.find(b) != -1) return ans;
        s += a;
        ans++;
        if(s.find(b) != -1) return ans;
        return -1;
    }
};