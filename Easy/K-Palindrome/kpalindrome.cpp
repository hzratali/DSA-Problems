//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string s  = str;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        reverse(s.begin(), s.end());
        int res = lcs(str, s, 0, 0, dp);
        return n-res<=k;
    }
    int lcs(string &str, string &s, int i, int j, vector<vector<int>>&dp){
        if(i>=str.size() || j>=s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(str[i] == s[j]) ans = max(ans, 1+lcs(str, s, i+1, j+1, dp));
        else{
            ans = max(ans, lcs(str, s, i+1, j, dp));
            ans = max(ans, lcs(str, s, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends