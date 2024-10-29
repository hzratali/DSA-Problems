class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            vis[i][0] = 1;
            q.push({i, 0, 0});
        }
        int dirs[3] = {-1, 0, 1};
        int mxMoves = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<int> v = q.front(); q.pop();
                int r = v[0], c = v[1], cnt = v[2];
                mxMoves = max(mxMoves, cnt);
                for(int d : dirs){
                    int nRow = r+d, nCol = c+1;
                    if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && !vis[nRow][nCol] && grid[r][c]<grid[nRow][nCol]){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol, cnt+1});
                    }
                }
            }
        }
        return mxMoves;
    }
};