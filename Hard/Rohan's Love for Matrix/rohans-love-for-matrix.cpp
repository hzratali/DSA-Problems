//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod = 1e9+7;
        vector<int> fib(n+1, 0);
        fib[1] = 1;
        for(int i=2; i<n+1; i++){
            fib[i] = (fib[i-1] % mod + fib[i-2] % mod) % mod;
        }
        return fib[n];
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends