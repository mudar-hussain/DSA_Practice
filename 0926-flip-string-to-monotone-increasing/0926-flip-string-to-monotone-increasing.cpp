class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_flip = 0;
        int count_one = 0;
        for(char c: s){
            if(c == '1')
                count_one++;
            else
                count_flip++;
            count_flip = min(count_one, count_flip);
        }
        return count_flip;
    }
};