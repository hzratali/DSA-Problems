//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    for(int i=0; i<s.size(); i++){
		        string temp;
		        temp.append(1, s[i]);
		        f(s, temp, i+1, ans);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
		void f(string s, string str, int ind, vector<string>&ans){
		    if(ind == s.length()){
		        ans.push_back(str);
		        return;
		    }
		    f(s, str, ind+1, ans);
		    f(s, str+s[ind], ind+1, ans);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends