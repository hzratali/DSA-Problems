class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return computeCost(s1, s2, s1.size()-1, s2.size()-1, dp);
    }
    int computeCost(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0){
            int deleteCost = 0;
            for(int p=0; p<=j; p++) deleteCost += s2[p];
            return deleteCost;
        }
        if(j < 0){
            int deleteCost = 0;
            for(int p=0; p<=i; p++) deleteCost += s1[p];
            return deleteCost;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = computeCost(s1, s2, i-1, j-1, dp);
        else{
            return dp[i][j] = min(s1[i] + computeCost(s1, s2, i-1, j, dp),
                       min(s2[j] + computeCost(s1, s2, i, j-1, dp),
                           s1[i] + s2[j] + computeCost(s1, s2, i-1, j-1, dp)));
        }
    }
};