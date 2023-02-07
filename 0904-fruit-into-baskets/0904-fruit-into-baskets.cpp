class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n<=2)
            return n;
        pair<int,int> p1 = {fruits[0], 0};
        int i = 0, j = 0;
        while(j<n && fruits[j] == p1.first){
            p1.second++;
            j++;
        }
        if(j == n)
            return n;
        pair<int, int> p2 = {fruits[j++], 1};
        int count = p1.second+1, ans = p1.second+1;
        p1.second = 0;
        while(j<n){
            if(fruits[j] == p1.first){
                p1.second++;
                p2.second = 0;
                count++;
            }else if(fruits[j] == p2.first){
                p2.second++;
                p1.second = 0;
                count++;
            }else{
                if(p1.second >= p2.second){
                    count = p1.second+1;
                    p2.first = fruits[j];
                    p2.second = 1;
                    p1.second = 0;
                }else{
                    count = p2.second+1;
                    p1.first = fruits[j];
                    p1.second = 1;
                    p2.second = 0;
                }
            }
            ans = max(ans, count);
            j++;
        }
        return ans;
        
    }
};