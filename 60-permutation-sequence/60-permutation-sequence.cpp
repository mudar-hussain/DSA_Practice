class Solution {
public:
    void solve(string& ans,int n, int f, vector<int>& digits, int k ){
        if(n==1){
            ans += to_string(digits.back());
            return;
        }
        int index = k/f;
        if(k%f == 0) index--;
        
        ans += to_string(digits[index]);
        digits.erase(digits.begin()+index);
        
        k -= f*index;
        f /= digits.size();
        solve(ans, n-1, f, digits, k);
    }
    string getPermutation(int n, int k) {
        string ans = "";
        int f = 1;
        vector<int> digits;
        for(int i = 1; i<n; i++){
            f *= i;
            digits.push_back(i);
        }
        digits.push_back(n);
        solve(ans, n, f, digits, k);
        return ans;
    }
};