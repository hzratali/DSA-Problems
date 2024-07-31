//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string ans = "";
        for(int i=0; i<min(arr[0].size(), arr[n-1].size()); i++){
            if(arr[0][i] != arr[n-1][i]) break;
            ans += arr[0][i];
        }
        return ans=="" ? "-1":ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends