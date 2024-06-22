//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long ans = -1;
        string store = "";
        int flag = 0;
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == ' '){
                if(!store.empty() && (ans == -1 || stoll(store) > ans)) ans = stoll(store);
                store = "";
                flag = 0;
            }
            else if(flag == 1) continue;
            else if(sentence[i] >= 57){
                flag = 1;
                store = "";
            }
            else store += sentence[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends