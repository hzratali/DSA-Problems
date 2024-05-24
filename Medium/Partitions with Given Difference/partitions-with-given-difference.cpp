//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code herent sum=0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        sum=sum-d;
        if(sum<0 or sum%2!=0){
            return 0;
        }
        sum=sum/2;
        return solve(n,sum,0,arr,0,dp);
    }
    long M=1e9+7;
    int solve(int n,int sum,int cnt,vector<int>&arr,int i, vector<vector<int>>&dp){
        if(i==n){
            if(cnt==sum) return 1;
            return 0;
        }
        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        int inc=solve(n,sum,cnt+arr[i],arr,i+1,dp);
        int exc=solve(n,sum,cnt,arr,i+1,dp);
        return dp[i][cnt]=(inc+exc)%M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends