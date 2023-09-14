//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int currSum = 0;
        sort(arr, arr+n);
        vector<vector<int>> dp(n, vector<int>(sum, -1));
        return (f(arr, n, 0, sum, currSum, dp))%mod;
	}
	int f(int arr[], int n, int i, int sum, int currSum, vector<vector<int>>&dp){
	    if(currSum > sum) return 0;
	    if(sum == currSum) return 1;
	    if(i == n){
	        if(sum==currSum) return 1;
	        return 0;
	    }
	    if(i > n) return 0;
	    if(dp[i][currSum] != -1) return dp[i][currSum];
	    int notTake = f(arr, n, i+1, sum, currSum, dp);
	    int take = f(arr, n, i+1, sum, currSum+arr[i], dp);
	    return dp[i][currSum] = (take+notTake)%mod;
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends