class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                ans += f(i, j, matrix, dp);
            }
        }
        return ans;
    }
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= grid.size() || j >= grid[0].size()) return 0;
        if(grid[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = f(i, j+1, grid, dp);
        int dia = f(i+1, j+1, grid, dp);
        int below = f(i+1, j, grid, dp);
        return dp[i][j] = 1 + min(right, min(dia, below));
    }
};