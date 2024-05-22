//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        auto isValid = [](double mxDist, vector<int>&pos, int mxStation){
            int reqStation = 0;
            for(int i=1; i<pos.size(); i++){
                double dst = pos[i] - pos[i-1];
                reqStation += static_cast<int> (dst/mxDist);
            }
            return reqStation <= mxStation;
        };
        double l = 0, r = stations.back() - stations.front();
        double ans = r;
        while(r-l >= 1e-6){
            double m = (l+r)/2.0;
            if(isValid(m, stations, k)){
                r = m;
                ans = m;
            }
            else l = m;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends