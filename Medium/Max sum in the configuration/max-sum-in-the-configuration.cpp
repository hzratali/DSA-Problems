//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long currSum = 0;
        for(int i=0; i<n; i++) currSum += (long long)a[i];
        long long currVal = 0;
        for(int i=0; i<n; i++) currVal += (long long)i*a[i];
        long long nxtVal = 0, ans = 0;
        for(int i=0; i<n; i++){
            nxtVal = currVal - currSum + (long long)a[i]*n;
            currVal = nxtVal;
            ans = max(ans, currVal);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends