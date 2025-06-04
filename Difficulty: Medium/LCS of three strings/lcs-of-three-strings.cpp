class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        vector<vector<vector<int>>>dp(s1.length(),vector<vector<int>>(s2.length(),vector<int>(s3.length(),-1)));
        return f(s1,s2,s3,dp,0,0,0);
    }
    int f(string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp,int i,int j,int k){
        if(i>=s1.length() || j>=s2.length() || k>=s3.length()) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(s1[i]==s2[j] && s2[j]==s3[k]) ans = 1 + f(s1,s2,s3,dp,i+1,j+1,k+1);
        else ans=max({f(s1,s2,s3,dp,i+1,j,k), f(s1,s2,s3,dp,i,j+1,k), f(s1,s2,s3,dp,i,j,k+1)});
        return dp[i][j][k]=ans;
    }
};
