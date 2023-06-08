//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k){
        // code here
        vector<int> v;
        for(int i=1; i<=n; i++) v.push_back(i);
        int cnt = 1;
        while(cnt != k){
            next_permutation(v.begin(), v.end());
            cnt++;
        }
        string ans = "";
        for(int i=0; i<v.size(); i++) ans += to_string(v[i]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends