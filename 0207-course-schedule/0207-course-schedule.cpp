class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> inDeg(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
            inDeg[x[0]]++;
        }
        queue<int> q;
        //Push ll the nodes with indegree zero in the queue
        for(int i=0; i<numCourses; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        int vis = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            vis++;
            for(auto x : adj[node]){
                inDeg[x]--;
                if(inDeg[x] == 0) q.push(x);
            }
        }
        return vis == numCourses;
    }
};