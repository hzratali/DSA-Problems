//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> ans(n+1);
        ans[1] = 1;
        for(int i=2; i<=n; i++){
            if(i%2 == 0) ans[i] = 2;
            else ans[i] = prime(i);
        }
        return ans;
    }
    int prime(int n){
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0) return i;
        }
        return n;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends