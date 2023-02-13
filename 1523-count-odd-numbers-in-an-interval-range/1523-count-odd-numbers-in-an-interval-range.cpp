class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high){
            return low%2;
        }
        if(low%2 && high%2)
            return (high-low)/2 - 1 + low%2 + high%2;
        else
            return (high-low)/2 + low%2 + high%2;
            
    }
};