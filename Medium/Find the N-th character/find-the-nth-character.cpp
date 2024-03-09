//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        if(r==0) return s[n];
        string st = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                st.push_back('1');
                st.push_back('0');
            }
            else{
                st.push_back('0');
                st.push_back('1');
            }
            if(st.size() > n) break;
        }
        return nthCharacter(st, r-1, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends