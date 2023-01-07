class Solution {
public:
    int minPartitions(string n) {
        int count = 0;
        for(char c: n){
            count = max(count, c-'0');
            if(count == 9)
                return count;
        }
        return count;
    }
};