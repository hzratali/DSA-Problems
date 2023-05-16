class Solution {
public:
    int mod = 1000000007;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        int ans = 0;
        for(int i=low; i<=high; i++){
            ans = ((ans%mod) + (solve(i, zero, one, dp)%mod))%mod;
        }
        return ans;
    }
    int solve(int ind, int zero, int one, vector<int>&dp){
        if(ind == 0) return 1;
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind]%mod;
        int forZero = solve(ind-zero, zero, one, dp);
        int forOne = solve(ind-one, zero, one, dp);
        return dp[ind] = (forZero+forOne)%mod;
    }
};