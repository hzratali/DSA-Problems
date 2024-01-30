//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[21][21][21];
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3){
        // your code here
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, n1, n2, n3, A, B, C);
    }
    int f(int i, int j, int k, int n1, int n2, int n3, string s1, string s2, string s3){
        if(i >= n1 or j>=n2 or k>=n3) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(s1[i]==s2[j] && s2[j]==s3[k]){
            return dp[i][j][k] = 1 + f(i+1, j+1, k+1, n1, n2, n3, s1, s2, s3);
        }
        return dp[i][j][k] = max(f(i+1, j, k, n1, n2, n3, s1, s2, s3), max(f(i, j+1, k, n1, n2, n3, s1, s2, s3), f(i, j, k+1, n1, n2, n3, s1, s2, s3)));
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends