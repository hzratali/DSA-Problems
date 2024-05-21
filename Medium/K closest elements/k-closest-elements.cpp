//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int index = f(arr, 0, n-1, x);
        int lInd = index, rInd = index+1;
        if(lInd>=0 && arr[lInd]==x) lInd--;
        vector<int> ans;
        for(int i=0; i<k; i++){
            if(lInd>=0 && rInd<n){
                int leftDiff = x-arr[lInd];
                int rightDiff = arr[rInd]-x;
                if(leftDiff < rightDiff){
                    ans.push_back(arr[lInd]);
                    lInd--;
                }
                else{
                    ans.push_back(arr[rInd]);
                    rInd++;
                }
            }
            else if(lInd >= 0){
                ans.push_back(arr[lInd]);
                lInd--;
            }
            else{
                ans.push_back(arr[rInd]);
                rInd++;
            }
        }
        return ans;
    }
    int f(vector<int>&arr, int l, int r, int x){
        if(arr[r]<=x) return r;
        if(arr[l] > x) return l;
        int m = (l+r)/2;
        if(arr[m]<=x && arr[m+1]>x) return m;
        else if(arr[m]<x) return f(arr, m+1, r, x);
        return f(arr, l, m-1, x);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends