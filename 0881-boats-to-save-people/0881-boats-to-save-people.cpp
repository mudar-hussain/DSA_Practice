class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int low = 0, high = people.size()-1;
        
        sort(people.begin(), people.end());
        int ans = 0;
        while(low<=high){
            if(people[low] + people[high] <= limit){
                low++;
                high--;
            }else{
                high--;
            }
            ans++;
        }
        return ans;
    }
};