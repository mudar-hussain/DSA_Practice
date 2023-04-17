class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        for(int i : candies)
            maxi = max(maxi, i);
        
        maxi -= extraCandies;
        vector<bool> v(candies.size(), false);
        for(int i = 0; i<candies.size(); i++){
            if(candies[i] >= maxi)
                v[i] = true;
        }
        return v;
    }
};