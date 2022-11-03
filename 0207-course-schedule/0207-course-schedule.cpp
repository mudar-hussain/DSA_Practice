class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        int inDeg[n+1];
        memset(inDeg, 0, sizeof(inDeg));
        int ans = 0;
        vector<vector<int>> adj(n);
        for(auto i: p){
            adj[i[1]].push_back(i[0]);
            inDeg[i[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(inDeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans++;
            for(int i: adj[temp]){
                inDeg[i]--;
                if(inDeg[i] == 0)
                    q.push(i);
            }
        }
        return ans == n;
    }
};