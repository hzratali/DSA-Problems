//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long int
class Solution {
  public:
    long long int InternalCount(ll p[], ll q[], ll r[]) {
        // code here
        // area of the triangle.
        ll area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1])) / 2;
        // no. of boundary(edge) points between two given points.
        ll b1 = __gcd(abs(p[0]-q[0]), abs(p[1] - q[1]));
        ll b2 = __gcd(abs(q[0]-r[0]), abs(q[1] - r[1]));
        ll b3 = __gcd(abs(r[0]-p[0]), abs(r[1] - p[1]));
        
        ll bps = b1 + b2 + b3;
        // no. of Integral points between two given points.
        ll integralPoints = area - bps/2 + 1;
        
        return integralPoints;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends