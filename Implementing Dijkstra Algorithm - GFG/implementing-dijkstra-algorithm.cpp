// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // int min(vector<int> pro, vector<int> dist, int V){
    //     int m = INT_MAX;
    //     int m_i;
    //     for(int i = 0; i<V; i++){
    //         if(pro[i] == 0 && dist[i]<=m){
    //             m = dist[i];
    //             m_i = i;
    //         }
    //     }
    //     return m_i;
    // }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V+1, INT_MAX);
        dist[S] = 0;
        set<pair<int, int>> s;
        s.insert(make_pair(dist[S], S));
        while(!s.empty()){
            auto itr = *(s.begin());
            int u_dist = itr.first;
            int u = itr.second;
            s.erase(itr);
            for(auto it: adj[u]){
                if(u_dist + it[1] < dist[it[0]]){
                    dist[it[0]] = u_dist + it[1];
                    s.insert(make_pair(dist[it[0]], it[0]));
                }
            }
            
        }
        
        
        
        // vector<int> pro(V, 0);
        // vector<int> dist(V, INT_MAX);
        // dist[S] = 0;
        // for(int i = 0; i<V-1; i++){
        //     int u = min(pro, dist, V);
        //     pro[u] = 1;
        //     for(int j = 0; j<V; j++){
        //         cout<<pro[j]<<" "<<adj[u][j][0]<<" ";
        //         if(pro[j] == 0 && adj[u][j][0] != 0 && dist[u] != INT_MAX){
        //             if(dist[u]+adj[u][j][1] < dist[j]){
        //                 dist[j] = dist[u]+adj[u][j][1];
        //             }
        //             cout<<dist[j];
        //         }
        //     }
            
        // }
        return dist;
    }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends