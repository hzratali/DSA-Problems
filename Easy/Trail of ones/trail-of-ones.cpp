//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        int mod = (int) 1e9+7;
        int prevFib = 1, currFib = 1, curr = 1;
        for(int i=3; i<=n; i++){
            curr = ((curr*2)%mod + currFib)%mod;
            int temp = prevFib;
            prevFib = currFib;
            currFib = (currFib + temp) % mod;
        }
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends