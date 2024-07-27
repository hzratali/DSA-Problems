//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
        //complete the function here
        int n = str.size();
        string temp = "";
        for(int i=n-1; i>=0; i--) temp += str[i];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - lcs(n-1, n-1, str, temp, dp);
    }
    int lcs(int i, int j, string s1, string s2, vector<vector<int>>&dp){
        if(i<0 || j<0)  return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1+lcs(i-1, j-1, s1, s2, dp);
        else return dp[i][j] = max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends