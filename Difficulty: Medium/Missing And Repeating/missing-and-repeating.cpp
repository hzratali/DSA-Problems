//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size(), xr = 0;
        for(int i=0; i<n; i++){
            xr ^= arr[i];
            xr ^= (i+1);
        }
        int k = xr & (~(xr-1));
        int ones = 0, zeros = 0;
        for(int i=0; i<n; i++){
            if(k&arr[i]) ones ^= arr[i];
            else zeros ^= arr[i];
            if(k & (i+1)) ones ^= (i+1);
            else zeros ^= (i+1);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == zeros) cnt++;
        }
        if(cnt == 2) return {zeros, ones};
        return {ones, zeros};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends