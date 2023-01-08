class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int time = 0;
        unordered_map<char, int> lastIdx;
        
        for(int i = 0; i<n; i++){
            for(char c: garbage[i]){
                time++;
                lastIdx[c] = i-1;
            }
        }
        for(int i = 1; i<n-1; i++){
            travel[i] += travel[i-1];
        }
        
        for(auto i: lastIdx){
            if(i.second>=0)
                time += travel[i.second];
        }
        
        return time;
    }
};