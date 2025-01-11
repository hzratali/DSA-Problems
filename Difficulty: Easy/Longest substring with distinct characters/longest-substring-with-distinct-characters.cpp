//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> mp(26, 0);
        int start = 0, mxLen = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            mp[ch-'a']++;
            while(mp[ch-'a'] > 1){
                mp[s[start]-'a']--;
                start++;
            }
            mxLen = max(mxLen, i-start+1);
        }
        return mxLen;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends