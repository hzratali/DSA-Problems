class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(matrix[r][c] != 0 and r>0) matrix[r][c] += matrix[r-1][c];
            }
            vector<int> row = matrix[r];
            sort(row.begin(), row.end(), greater());
            for(int i=0; i<m; i++) ans = max(ans,row[i]*(i+1));
        }
        return ans;
    }
};