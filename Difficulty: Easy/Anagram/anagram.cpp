//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        if(s1.size() != s2.size()) return false;
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        for(int i=0; i<s1.size(); i++){
           int idx=s1[i]-'a';
           a1[idx]++;
           int idy=s2[i]-'a';
           a2[idy]++;
        }
        return a1 == a2;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends