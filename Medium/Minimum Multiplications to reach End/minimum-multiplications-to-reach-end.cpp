//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        int mod = 100000;
        vector<int> mul(mod, INT_MAX);
        queue<pair<int, int>> q;
        q.push({start, 0});
        mul[start] = 0;
        while(!q.empty()){
            auto x = q.front(); q.pop();
            int num = x.first, steps = x.second;
            for(int a : arr){
                int n = (num*a)%mod;
                if(steps+1 < mul[n]){
                    mul[n] = steps+1;
                    if(n == end) return steps+1;
                    q.push({n, steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends