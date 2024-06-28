//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        for(int i=0;i<arr.size();i++){
            if(CheckPalindrome(arr[i]))
                return to_string(i) + " R";
        }
        for (int j = 0; j < arr.size(); j++) {
            vector<int> col(arr.size());
            for (int i = 0; i < arr.size(); i++) 
                col[i] = arr[i][j];
            
            if (CheckPalindrome(col)) 
                return to_string(j) + " C";
        }
        return "-1";
    }
    bool CheckPalindrome(vector<int>a){
        int len = a.size();
        for (int i = 0; i < len / 2; i++) {
            if (a[i] != a[len - i - 1])
                return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends