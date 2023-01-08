class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int pIdx = -1;
        int gIdx = -1;
        int mIdx = -1;
        int time = 0;
        
        for(int i = 0; i<n; i++){
            for(char c: garbage[i]){
                time++;
                if(c == 'P'){
                    pIdx = i;
                }else if(c == 'G'){
                    gIdx = i;
                }else if(c == 'M'){
                    mIdx = i;
                }
            }
        }
        
        for(int i = 0; i<n-1; i++){
            if(i<pIdx)
                time += travel[i];
            if(i<gIdx)
                time += travel[i];
            if(i<mIdx)
                time += travel[i];
            
        }
        
        return time;
    }
};