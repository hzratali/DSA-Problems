//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<int>> adj[N];
        for(auto x : edges) adj[x[0]].push_back({x[1], x[2]});
        vector<int> distance(N, INT_MAX);
        distance[0] = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int node = q.front(); q.pop();
            for(auto neibor : adj[node]){
                int nbr = neibor[0], dist = neibor[1];
                if(distance[node]+dist < distance[nbr]){
                    distance[nbr] = distance[node]+dist;
                    q.push(nbr);
                }
            }
        }
        for(auto &x : distance) x = (x == INT_MAX ? -1 : x);
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends