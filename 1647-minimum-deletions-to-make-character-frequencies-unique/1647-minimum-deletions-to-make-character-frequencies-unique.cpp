class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        for(char c: s){
            count[c-'a']++;
        }
        sort(count.begin(), count.end());
        int prev = 0;
        int ans = 0;
        stack<int> st;
        st.push(0);
        for(int i = 0; i<count.size(); i++){
            if(count[i] == 0)
                st.push(0);
            else if(count[i] == prev){
                if(st.empty()){
                    ans += count[i];
                    prev = count[i];
                    continue;
                }
                ans += (count[i] - st.top());
                st.pop();
            }
            else if(count[i] > prev+1){
                prev++;
                while(prev < count[i]){
                    st.push(prev);
                    prev++;
                }
            }
            prev = count[i];
        }
        
        return ans;
        
    }
};