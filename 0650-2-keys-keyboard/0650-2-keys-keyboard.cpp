class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n/2+1, 0));
        return 1 + f(1, 1, n, dp); //First step is always copy all operation
    }
    int f(int currLen, int pasteLen, int n, vector<vector<int>>&dp){
        if(currLen == n) return 0; // base case: reached n A's, dont need more operations
        if(currLen > n) return 1000; // base case: exceeded n A's not a valid sequence, so return max value
        // copy all + paste
        if(dp[currLen][pasteLen] != 0) return dp[currLen][pasteLen];
        int op1 = 2 + f(currLen*2, currLen, n, dp);
        // Paste
        int op2 = 1 + f(currLen+pasteLen, pasteLen, n, dp);
        dp[currLen][pasteLen] = min(op1, op2);
        return dp[currLen][pasteLen];
    }
};