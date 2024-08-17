class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> prevRow(m);
        for(int i=0; i<m; i++) prevRow[i] = points[0][i];
        for(int i=0; i<n-1; i++){
            vector<long long> leftMax(m);
            vector<long long> rightMax(m);
            vector<long long> currRow(m);
            //Calculate left-right max
            leftMax[0] = prevRow[0];
            for(int j=1; j<m; j++) leftMax[j] = max(leftMax[j-1]-1, prevRow[j]);
            //Calculate right-left max
            rightMax[m-1] = prevRow[m-1];
            for(int j=m-2; j>=0; j--) rightMax[j] = max(rightMax[j+1]-1, prevRow[j]);
            //Calculate curr row's max
            for(int j=0; j<m; j++) currRow[j] = points[i+1][j] + max(leftMax[j], rightMax[j]);
            //Update prevRow for the next iteration
            prevRow = currRow;
        }
        long long mxPoints = 0;
        for(int i=0; i<m; i++) mxPoints = max(mxPoints, prevRow[i]);
        return mxPoints;
    }
};