// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node,bool graph[101][101],int color[],int n,int col){
    
    for(int i=0;i<n;i++){
        if((i!=node)&&graph[node][i]&&color[i]==col)return false;
    }
    return true;
}
bool solve(int node,bool graph[101][101],int color[],int n,int m){
    if(node==n)return true;
    for(int i=1;i<=m;i++){
        if(isSafe(node,graph,color,n,i)){
            color[node]=i;
            if(solve(node+1,graph,color,n,m))return true;
            color[node]=0;
        }
    }
    return false;
    
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int n=V;
    int color[n];
    memset(color,0,sizeof(color));
      return solve(0,graph,color,n,m);
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