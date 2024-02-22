//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod = 1e9+7;
    int subsequenceCount(string s, string t){
      //Your code here
      int n = s.size(), m = t.size();
      vector<vector<int>> dp(n, vector<int>(m, -1));
      return f(0, 0, n, m, s, t, dp);
    }
    int f(int i, int j, int n, int m, string s, string t, vector<vector<int>> &dp){
        if(j >= m) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans = (f(i+1, j+1, n, m, s, t, dp)+f(i+1, j, n, m, s, t, dp))%mod;
        }
        else ans = f(i+1, j, n, m, s, t, dp);
        return dp[i][j] = ans;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends