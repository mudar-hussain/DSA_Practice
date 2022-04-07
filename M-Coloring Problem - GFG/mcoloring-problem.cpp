// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101], int i, int c, vector<int> color, int V){
    for(int j = 0; j<V; j++){
        if(graph[i][j] == 1 && color[j] == c) return false;
    }
    
    return true;
}

bool solve(bool graph[101][101], int m, int V, vector<int> color, int i){
    
    if(i == V) return true;
    
    for(int c = 0; c<m; c++){
        if(isSafe(graph, i, c, color, V)){
            
            color[i] = c;
            
            if(solve(graph, m, V, color, i+1)) return true;
            
            color[i] = c;
            
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> color(V, -1);
    return solve(graph, m, V, color, 0);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends