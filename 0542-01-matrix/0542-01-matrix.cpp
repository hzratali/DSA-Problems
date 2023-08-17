class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            for(int k=0; k<4; k++){
                int r = x+dx[k];
                int c = y+dy[k];
                if(r>=0 && r<n && c>=0 && c<m && ans[r][c]==-1){
                    ans[r][c] = ans[x][y]+1;
                    q.push({r, c});
                }
            }
            q.pop();
        }
        return ans;
    }
};