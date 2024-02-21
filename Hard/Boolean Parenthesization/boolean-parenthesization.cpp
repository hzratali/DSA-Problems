//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int countWays(int n, string s){
        // code here
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        return dfs(s, 0, n-1, dp).first;
    }
    pair<int, int> dfs(string &s, int l, int h, vector<vector<pair<int, int>>>&dp){
        if(l==h){
            if(s[l] == 'T') return {1, 0};
            else return {0, 1};
        }
        if(dp[l][h] != make_pair(-1, -1)) return dp[l][h];
        long long t = 0, f = 0;
        for(int i=l; i<h; i+=2){
            auto left = dfs(s, l, i, dp);
            auto right = dfs(s, i+2, h, dp);
            if(s[i+1] == '|'){
                t = (t + (left.first*right.first+left.first*right.second+left.second*right.first)%mod)%mod;
                f = (f + left.second * right.second)%mod;
            }
            else if(s[i+1]=='&'){
                t = (t + left.first*right.first)%mod;
                f = (f + (left.first*right.second+left.second*right.first+left.second*right.second)%mod)%mod;
            }
            else{
                t = (t+(left.first*right.second+left.second*right.first)%mod)%mod;
                f = (f+(left.first*right.first+left.second*right.second)%mod)%mod;
            }
        }
        return dp[l][h] = {t, f};
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends