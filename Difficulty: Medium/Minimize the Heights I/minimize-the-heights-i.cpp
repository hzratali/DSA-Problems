//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n == 1) return 0; // No difference with one tower
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        // Step 2: Calculate initial difference
        int result = arr[n-1] - arr[0];
        // Step 3: Iterate through the array and compute the possible differences
        for(int i = 1; i < n; i++){
            int max_height = max(arr[i-1] + k, arr[n-1] - k);
            int min_height = min(arr[0] + k, arr[i] - k);
            // Update the result with the new difference
            result = min(result, max_height - min_height);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends