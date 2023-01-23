class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0)
            if(n == 1)
                return 1;
            else return -1;
        vector<int> zero(n+1, 0);
        vector<int> one(n+1, 0);
        for(auto i: trust){
            zero[i[0]]++;
            one[i[1]]++;
        }
        for(int i = 1; i<=n; i++){
            if(zero[i] == 0 && one[i] == n-1)
                return i;
        }
        return -1;
    }
};