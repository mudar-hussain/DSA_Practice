class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int ans = 0;
        unordered_map<int,int> um;
        for(int i: tasks){
            um[i]++;
        }
        for(auto i: um){
            if(i.second == 1){
                return -1;
            }else if(i.second % 3 == 0){
                ans += i.second/3;
            }else if(i.second % 3 == 2){
                ans += i.second/3 + 1;
            }else if(i.second == 4){
                ans += 2;
            }else if(i.second % 3 == 1){
                ans += i.second/3 + 1;
            }
        }
        return ans;
    }
};