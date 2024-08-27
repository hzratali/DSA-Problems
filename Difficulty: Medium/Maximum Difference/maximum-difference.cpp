//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> left_smaller(n+1,0), right_smaller(n + 1, 0);
        
        stack<int> l, r;
        l.push(arr[0]);
        for (int i = 1; i < n; ++i) {
            while (l.size() > 0 && l.top() >= arr[i]) l.pop();
            left_smaller[i] = l.size() > 0 ? l.top() : 0;
            l.push(arr[i]);
        }
        r.push(arr[n-1]);
        for (int i = n - 2; i >= 0; i--) {
            while (r.size() > 0 && r.top() >= arr[i]) r.pop();
            right_smaller[i] = r.size() > 0 ? r.top(): 0;
            r.push(arr[i]);
        }
        
        int mx = 0;
        for (int i = 0; i < n; ++i) mx = max(mx, abs(left_smaller[i] - right_smaller[i]));
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends