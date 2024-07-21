//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n = arr.size(), mxNeg = INT_MIN;
        if(n == 0) return 0;
        long long int prod = 1, cntNeg = 0, cntZero = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                cntZero++;
                continue;
            }
            if(arr[i] < 0){
                cntNeg++;
                mxNeg = max(mxNeg, arr[i]);
            }
            prod = (prod * arr[i]) % 1000000007;
        }
        if(cntZero == n) return 0;
        if(cntNeg%2 != 0) prod /= mxNeg;
        return prod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends