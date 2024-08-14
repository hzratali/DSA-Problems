//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) ans = max(ans, f(i, j, str1, str2, dp));
        }
        return ans;
    }
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends