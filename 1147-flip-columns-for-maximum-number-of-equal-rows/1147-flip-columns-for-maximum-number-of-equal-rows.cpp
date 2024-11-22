class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), mxIdenticalRows = 0;
        for(auto row : matrix){
            vector<int> flipRow(m);
            int identicalRowCnt = 0;
            for(int j=0; j<m; j++) flipRow[j] = 1 - row[j];
            for(auto compRow : matrix){
                if(compRow == row || compRow == flipRow) identicalRowCnt++;
            }
            mxIdenticalRows = max(mxIdenticalRows, identicalRowCnt);
        }
        return mxIdenticalRows;
    }
};