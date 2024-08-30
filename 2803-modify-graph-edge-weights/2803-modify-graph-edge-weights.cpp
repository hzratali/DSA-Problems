class Solution {
public:
    const int mx = 2e9;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currShortestDis = dijkstra(edges, n, source, destination);
        if(currShortestDis < target) return {};
        bool matchesTarget = (currShortestDis == target);
        for(vector<int> &edge : edges){
            if(edge[2] > 0) continue;
            edge[2] = matchesTarget ? mx : 1;
            if(!matchesTarget){
                long long newDis = dijkstra(edges, n, source, destination);
                //If the new distance is within the target range, update edge
                //weight to match target
                if(newDis <= target){
                    matchesTarget = true;
                    edge[2] += target - newDis;
                }
            }
        }
        return matchesTarget ? edges : vector<vector<int>>{};
    }
    long long dijkstra(vector<vector<int>> &edges, int n, int src, int des){
        vector<vector<long long>> adj(n, vector<long long>(n, mx));
        vector<long long> mnDis(n, mx);
        vector<bool> vis(n, false);
        mnDis[src] = 0;
        for(vector<int> &edge : edges){
            if(edge[2] != -1){
                adj[edge[0]][edge[1]] = edge[2];
                adj[edge[1]][edge[0]] = edge[2];
            }
        }
        for(int i=0; i<n; i++){
            int neiUnvisitedNode = -1;
            for(int j=0; j<n; j++){
                if(!vis[j] && (neiUnvisitedNode==-1 || mnDis[j]<mnDis[neiUnvisitedNode])){
                    neiUnvisitedNode = j;
                }
            }
            vis[neiUnvisitedNode] = true;
            for(int v=0; v<n; v++){
                mnDis[v] = min(mnDis[v], mnDis[neiUnvisitedNode]+adj[neiUnvisitedNode][v]);
            }
        }
        return mnDis[des];
    }
};