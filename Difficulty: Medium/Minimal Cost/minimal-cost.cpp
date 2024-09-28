//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, n, arr, dp);
    }
    int f(int i, int k, int n, vector<int>&arr, vector<int>&dp){
        if(i == n-1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j=i+1; j<=min(i+k, n-1); j++) ans = min(ans, abs(arr[i]-arr[j])+f(j, k, n, arr, dp));
        return dp[i] = ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends