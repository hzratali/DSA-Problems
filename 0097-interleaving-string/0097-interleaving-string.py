class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        int[][] dp = new int[s1.length()+1][s2.length()+1];
        for(int[] row : dp) Arrays.fill(row, -1);
        return f(0, 0, s1, s2, s3, dp);
    }
    boolean f(int i, int j, String s1, String s2, String s3, int[][] dp){
        if(i+j == s3.length()) return true;
        if(dp[i][j] != -1) return dp[i][j] == 1;;
        boolean ans = false;
        if(i<s1.length() && s1.charAt(i)==s3.charAt(i+j)) ans |= f(i+1, j, s1, s2, s3, dp);
        if(j<s2.length() && s2.charAt(j)==s3.charAt(i+j)) ans |= f(i, j+1, s1, s2, s3, dp);
        dp[i][j] = ans ? 1 : 0;
        return ans;
    }
}