class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int, int> mp;
        int n = fruits.size();
        int count = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            mp[fruits[j]]++;
            count++;
            
            if(mp.size()<=2)
                j++;
            else if(mp.size()>2){
                count--;
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
                j++;
            }
        }
        return count;
        
    }
};