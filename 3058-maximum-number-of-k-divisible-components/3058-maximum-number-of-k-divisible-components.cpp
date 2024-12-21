class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int compCnt = 0;
        dfs(0, -1, adj, values, k, compCnt);
        return compCnt;
    }
    int dfs(int currNode, int parentNode, vector<int> adj[], vector<int> &nodeValues, int k, int &cnt){
        int sum = 0;
        for(auto neiNode : adj[currNode]){
            if(neiNode != parentNode){
                sum += dfs(neiNode, currNode, adj, nodeValues, k, cnt);
                sum %= k;
            }
        }
        sum += nodeValues[currNode];
        sum %= k;
        if(sum == 0) cnt++;
        return sum;
    }
};