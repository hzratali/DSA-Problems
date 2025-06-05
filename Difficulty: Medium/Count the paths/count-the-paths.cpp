class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto x : edges) adj[x[0]].push_back(x[1]);
        vector<int> dp(V, -1);
        return dfs(src, dest, adj, dp);
    }
    int dfs(int node, int dest, vector<vector<int>>&adj, vector<int>&dp){
        if(node == dest) return 1;
        if(dp[node] != -1) return dp[node];
        int pathCnt = 0;
        for(int nei : adj[node]) pathCnt += dfs(nei, dest, adj, dp);
        return dp[node] = pathCnt;
    }
};