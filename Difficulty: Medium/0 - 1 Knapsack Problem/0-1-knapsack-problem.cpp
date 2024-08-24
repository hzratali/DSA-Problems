//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = wt.size();
        vector<vector<int>> dp(W+1, vector<int>(n, -1));
        return solve(W, wt, val, 0, dp);
    }
    int solve(int w, vector<int>&wt, vector<int>&val, int i, vector<vector<int>>&dp){
        if(i >= wt.size()) return 0;
        if(dp[w][i] != -1) return dp[w][i];
        int ans = 0;
        if(w-wt[i] >= 0) ans = max(ans, val[i] + solve(w-wt[i], wt, val, i+1, dp));
        ans = max(ans, solve(w, wt, val, i+1, dp));
        return dp[w][i] = ans;
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends