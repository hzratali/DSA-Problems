//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Moves array representing the allowed moves from each digit
        vector<vector<int>> arr = {
            {0, 8},           // from 0 to 0, 8
            {1, 2, 4},        // from 1 to 1, 2, 4
            {2, 1, 3, 5},     // from 2 to 2, 1, 3, 5
            {3, 2, 6},        // from 3 to 3, 2, 6
            {4, 1, 5, 7},     // from 4 to 4, 1, 5, 7
            {5, 2, 4, 6, 8},  // from 5 to 5, 2, 4, 6, 8
            {6, 3, 5, 9},     // from 6 to 6, 3, 5, 9
            {7, 4, 8},        // from 7 to 7, 4, 8
            {8, 0, 5, 7, 9},  // from 8 to 8, 0, 5, 7, 9
            {9, 6, 8}         // from 9 to 9, 6, 8
        };
        // Memoization table: dp[length][digit] = number of sequences of 'length' ending in 'digit'
        vector<vector<long long>> dp(n + 1, vector<long long>(10, -1));
        long long ans = 0;
        // Calculate the number of sequences of length 'n' for each digit
        for (int i = 0; i <= 9; ++i) {
            ans += countSequences(n, i, arr, dp);
        }
        return ans;
    }
    long long countSequences(int length, int digit, vector<vector<int>>& moves, vector<vector<long long>>& dp) {
        // Base case: if length is 1, there's only one sequence for each digit
        if (length == 1) return 1;
        // Check if the result is already computed
        if (dp[length][digit] != -1) return dp[length][digit];
        // Compute the result
        long long total = 0;
        for (int move : moves[digit]) {
            total += countSequences(length - 1, move, moves, dp);
        }
        dp[length][digit] = total;
        return total;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends