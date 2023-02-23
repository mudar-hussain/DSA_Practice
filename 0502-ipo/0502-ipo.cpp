class Solution {
    
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> maxP;
        vector<pair<int,int>> minC(n);
        for(int i = 0; i<n; i++){
            minC[i] = make_pair(capital[i], profits[i]);
        }
        sort(minC.begin(), minC.end());
        int i = 0;
        while(k--){
            while(i<n && minC[i].first <= w){
                maxP.push(minC[i].second);
                i++;
            }
            if(!maxP.empty()){
                w += maxP.top();
                maxP.pop();
            }else
                break;
        }
        return w;
        
    }
};