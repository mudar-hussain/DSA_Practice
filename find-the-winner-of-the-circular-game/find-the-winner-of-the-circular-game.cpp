class Solution {
public:
    int solve (vector<int> in, int k, int current){
        if(in.size()==1){
            return in[0];
        }
        current = ((current+k)%in.size());
        in.erase(in.begin()+current);
        return solve(in,k,current);
    }
    int findTheWinner(int n, int k) {
        vector<int> in ;
        for(int i=1; i<=n; i++){
            in.push_back(i);
        }
        return solve(in,k-1,0);
    }
};