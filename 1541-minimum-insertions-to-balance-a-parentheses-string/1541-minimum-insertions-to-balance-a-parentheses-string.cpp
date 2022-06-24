class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.length();
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(')
                cnt++;
            else{
                if(i == n-1 || (i+1<n && s[i+1] != ')'))
                    ans++;
                else
                    i++;
                
                if(cnt == 0)
                    ans++;
                else
                    cnt--;
            }
        }
        ans += cnt*2;
        return ans;
        
    }
};