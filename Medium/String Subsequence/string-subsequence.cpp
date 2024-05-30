//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int countWays(string s1, string s2) {
        // code here
        dp.resize(s1.size(), vector<int>(s2.size(), -1));
        return f(s1.size()-1, s2.size()-1, s1, s2);
    }
    int f(int i, int j, string &s1, string &s2){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i]==s2[j]) dp[i][j] = (f(i-1, j-1, s1, s2)+f(i-1, j, s1, s2))%mod;
        else dp[i][j] = f(i-1, j, s1, s2) % mod;
        return dp[i][j];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends