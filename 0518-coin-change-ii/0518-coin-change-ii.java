class Solution {
    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length][amount+1];
        for(int[] row : dp) Arrays.fill(row, -1);
        return f(0, amount, coins, dp);
    }
    int f(int i, int amount, int[] coins, int[][] dp){
        if(amount == 0) return 1;
        if(i == coins.length) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(coins[i] > amount) return dp[i][amount] = f(i+1, amount, coins, dp);
        int take = f(i, amount-coins[i], coins, dp);
        int notTake = f(i+1, amount, coins, dp);
        return dp[i][amount] = take+notTake;
    }
}