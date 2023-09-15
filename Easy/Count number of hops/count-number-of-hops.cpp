//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long mod = 1e9+7;
    long long countWays(int n){
        // your code here
        vector<long long> dp(n+1, -1);
        return f(n, dp);
    }
    long long f(int i, vector<long long> &dp){
        if(i == 0) return 1;
        if(i==1 || i==2) return i;
        if(dp[i] != -1) return dp[i];
        long long x = f(i-1, dp);
        long long y = f(i-2, dp);
        long long z = f(i-3, dp);
        return dp[i] = (x+y+z)%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends