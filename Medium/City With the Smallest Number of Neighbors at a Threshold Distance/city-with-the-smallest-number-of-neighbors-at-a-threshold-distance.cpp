//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int ansNode;
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<pair<int, int>> adj[n];
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int reachable = bfs(i, adj, n, m, distanceThreshold);
            if(ans >= reachable){
                ans = reachable;
                ansNode = i;
            }
        }
        return ansNode;
    }
    int bfs(int st, vector<pair<int,int>> adj[], int n, int m, int dis){
        vector<int> dist(n, INT_MAX);
        dist[st] = 0;
        queue<int> q;
        q.push(st);
        int cnt = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto x : adj[node]){
                int n1 = x.first, wt = x.second;
                if(dist[n1] > dist[node]+wt){
                    dist[n1] = dist[node]+wt;
                    q.push(n1);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dist[i] != 0){
                if(dist[i] <= dis) cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends