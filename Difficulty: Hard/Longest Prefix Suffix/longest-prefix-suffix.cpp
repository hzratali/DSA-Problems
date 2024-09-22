//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n = str.size();
        vector<int> lps(n, 0);
        int i = 1, len = 0; // i Pointer to traverse the string, len is Length of longest prefix that is also a suffix
        while(i < n){
            if(str[i] == str[len]){
                lps[i] = ++len;
                i++;
            }
            else{
                //If len is greater than 0, backtrack to the previous lps value
                if(len > 0) len = lps[len-1];
                //if len is 0, just move forward and set lps[i] to 0
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends