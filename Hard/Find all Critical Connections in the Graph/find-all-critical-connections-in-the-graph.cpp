//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
	    vector<int> rank(v, -1);
	    int k = dfs(adj, 0, rank, ans, 0, v);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
	int dfs(vector<int> graph[], int i, vector<int>&rank, vector<vector<int>>&ans, int prev, int n){
	    rank[i] = prev+1;
	    int t = INT_MAX;
	    for(auto nbr : graph[i]){
	        if(rank[nbr] == -1){
	            int k = dfs(graph, nbr, rank, ans, prev+1, n);
	            if(k > rank[i]) ans.push_back({min(i, nbr), max(i, nbr)});
	            t = min(t, k);
	        }
	        else if(rank[nbr] == n+1) continue;
	        else if(rank[nbr] != prev) t = min(t, rank[nbr]);
	    }
	    rank[i] = n+1;
	    return t;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends