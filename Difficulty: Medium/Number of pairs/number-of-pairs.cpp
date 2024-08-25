//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &x, vector<int> &y) {
        // Your Code goes here.
        vector<int> suffix(1002);
        long long ans = 0;
        for(int i=0; i<y.size(); i++) suffix[y[i]]++;
        for(int i=1000; i>=3; i--) suffix[i] += suffix[i+1];
        for(int i=0; i<x.size(); i++){
            if(x[i] == 1) continue;
            else if(x[i] == 2) ans += suffix[1] + suffix[5];
            else if(x[i] == 3) ans += suffix[1] + suffix[2] + suffix[4];
            else ans += suffix[1] + suffix[x[i]+1];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends