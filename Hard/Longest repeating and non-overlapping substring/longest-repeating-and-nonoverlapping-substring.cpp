//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        int curr=0, i=0;
        string ans = "-1";
        while(i < n){
            int t=1;
            string temp = s.substr(i, t);
            while(2*t <= n && s.substr(i+t).find(temp) != string::npos){
                if(curr < t){
                    curr = t;
                    ans = temp;
                }
                t++;
                temp = s.substr(i, t);
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends