//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string s;
	    f(ans, s, 0, 0, n);
	    return ans;
	}
	void f(vector<string>&ans, string s, int one, int zero, int n){
	    if(s.size() == n){
	        ans.push_back(s);
	        return;
	    }
	    s.push_back('1');
	    f(ans, s, one+1, zero, n);
	    if(one > zero){
	        s.pop_back();
	        s.push_back('0');
	        f(ans, s, one, zero+1, n);
	    }
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends