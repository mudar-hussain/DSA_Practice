// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	// Krushkal Algo
	int find(int i, vector<int> parent){
	    if(parent[i] == i)
	        return i;
	   
	   return find(parent[i], parent);
	}
	
	void unionn(int pu, int pv, vector<int> &parent, vector<int> &rank){
	    if(rank[pu] < rank[pv])
	        parent[pu] = pv;
	   else if(rank[pu] > rank[pv])
	        parent[pv] = pu;
	   else {
	       parent[pu] = pv;
	       rank[pv]++;
	   }
	}
	
	int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> parent(V);
        for(int i = 0; i<V; i++){
            parent[i] = i;
            for(auto x: adj[i]){
                pq.push({x[1], {i, x[0]}});
            }
        }
        vector<int> rank(V, 0);
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int wt = cur.first;
            int u = cur.second.first;
            int v = cur.second.second;
            int pu = find(u, parent);
            int pv = find(v, parent);
            if(pu != pv){
                ans += wt;
                unionn(pu, pv, parent, rank);
            }
        }
        return ans;
        
        
        
    }
	
	//Prism Algo
	
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     // code here
        
    //     int ans = 0;
        
    //     vector<int> vis(V, 0);
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //     q.push({0, 0});
        
    //     while(!q.empty()){
    //         auto cur = q.top();
    //         q.pop();
    //         if(vis[cur.second]) 
    //             continue;
    //         ans += cur.first;
            
    //         vis[cur.second]++;
    //         for(auto i: adj[cur.second]){
    //             q.push({i[1], i[0]});
    //         }
    //     }
    //     return ans;
    // }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends