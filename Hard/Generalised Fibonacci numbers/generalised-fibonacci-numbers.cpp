//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long
class Solution {
  public:
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        if(n <= 2) return 1LL%m;
        vector<vector<ll>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<ll>> ans = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while(n > 0){
            if(n&1) ans = multiply(ans, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (ans[0][0]+ans[0][1]+c*ans[0][2]) % m;
    }
    vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B, ll m) {
        int size = A.size();
        vector<vector<ll>> result(size, vector<ll>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends