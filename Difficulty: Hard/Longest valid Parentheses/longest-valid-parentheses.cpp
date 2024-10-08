//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        stack<int> st;
        st.push(-1);
        int mxLen = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    int len = i-st.top();
                    mxLen = max(mxLen, len);
                }
            }
        }
        return mxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends