//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> ans;
        int m = pat.size();
        int n = txt.size();
        if (m > n) return ans; // If pattern is longer than text, no match is possible.
        const int prime = 101; // A prime number used for the hash function
        const int base = 256;  // Base value (number of characters in the input alphabet)
        int patHash = 0, txtHash = 0, h = 1;
        // Compute the hash value of the pattern and the first window of text
        for(int i = 0; i < m - 1; i++) h = (h * base) % prime;
        for (int i = 0; i < m; i++) {
            patHash = (patHash * base + pat[i]) % prime;
            txtHash = (txtHash * base + txt[i]) % prime;
        }
        // Slide the pattern over the text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check if the hash values match
            if (patHash == txtHash) {
                // If hash values match, check characters one by one
                if (txt.substr(i, m) == pat) {
                    ans.push_back(i);
                }
            }
            // Calculate hash value for the next window of text
            if (i < n - m) {
                txtHash = (base * (txtHash - txt[i] * h) + txt[i + m]) % prime;
                // Ensure the hash value is positive
                if (txtHash < 0) txtHash += prime;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends