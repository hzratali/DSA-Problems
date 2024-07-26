//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool kPangram(string str, int k) {
        // code here
        vector<int> freq(26, 0);
        for(char c : str){
            if(c != ' ') freq[c-'a']++;
        }
        int cntZero = 0, cntNonZero = 0, cnt = 0;
        for(int i=0; i<26; i++){
            cnt += freq[i];
            if(freq[i] != 0) cntNonZero++;
            else cntZero++;
        }
        if(cntNonZero == 26 || (k >= cntZero && cnt>=26)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends