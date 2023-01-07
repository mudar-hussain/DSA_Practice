class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff = 0;
        int n = cost.size();
        int startingIdx = 0, currFuel = 0;
        for(int i = 0; i<n; i++){
            diff += gas[i]-cost[i];
            currFuel += gas[i]-cost[i];
            
            if(currFuel < 0){
                currFuel = 0;
                startingIdx = i+1;
            }
        }
        
        if(diff<0)
            return -1;
        return startingIdx;
    }
};