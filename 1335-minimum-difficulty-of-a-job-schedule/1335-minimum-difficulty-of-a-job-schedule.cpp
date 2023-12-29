class Solution {
public:
    int dp[301][11];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        memset(dp, -1, sizeof(dp));
        if(n < d) return -1;
        return f(jobDifficulty, n, 0, d);
    }
    int f(vector<int> &jobD, int n, int i, int d){
        if(d == 1) return *max_element(jobD.begin()+i, jobD.end());
        if(dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX, curr = INT_MIN;
        for(int j=i; j<=n-d; j++){
            curr = max(curr, jobD[j]);
            ans = min(ans, curr + f(jobD, n, j+1, d-1));
        }
        return dp[i][d] = ans;
    }
};