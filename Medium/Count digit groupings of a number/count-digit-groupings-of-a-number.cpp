//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[101][901];
	int TotalCount(string str){
	    // Code here
	    memset(dp, -1, sizeof(dp));
	    return f(0, 0, str);
	}
	int f(int i, int prevSum, string &s){
	    if(i == s.size()) return 1;
	    if(dp[i][prevSum] != -1) return dp[i][prevSum];
	    int sum = 0, ans = 0;
	    for(int j=i; j<s.size(); j++){
	        sum += (s[j]-'0');
	        if(sum >= prevSum) ans += f(j+1, sum, s);
	    }
	    return dp[i][prevSum] = ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends