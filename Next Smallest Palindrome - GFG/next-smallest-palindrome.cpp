//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    int m = n/2;
	    int l = m-1;
	    int r = (n%2==1) ? m+1 : m;
	    while(l>=0 && num[l]==num[r]){
	        l--;
	        r++;
	    }
	    vector<int> ans;
	    int carry = 0;
	    if(l<0 || num[l]<num[r]) carry = 1;
	    l = (n%2==0) ? m-1 : m;
	    r = m;
	    while(l >= 0){
	        num[l] = num[l]+carry;
	        carry = num[l]/10;
	        num[l] = num[l]%10;
	        num[r] = num[l];
	        l--; r++;
	    }
	    if(carry == 1){
	        num[n-1] = 1;
	        ans.push_back(1);
	    }
	    for(int i=0; i<n; i++) ans.push_back(num[i]);
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
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends