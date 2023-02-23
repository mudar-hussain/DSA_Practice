class Solution {
    
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pair<int,int>> maxP;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minC;
        for(int i = 0; i<n; i++){
            minC.push(make_pair(capital[i], profits[i]));
        }
        while(k--){
            while(!minC.empty() && minC.top().first <= w){
                maxP.push({minC.top().second, minC.top().first});
                minC.pop();
            }
            if(!maxP.empty()){
                w += maxP.top().first;
                maxP.pop();
            }
        }
        return w;
        
    }
};