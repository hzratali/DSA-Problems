//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int *left = new int[n];
        int *right = new int[n];
        left[0] = arr[0];
        int maxi = -1;
        for(int i = 1; i<n;i++ ){
            left[i] = min(arr[i] , left[i-1]);
        }
        right[n-1] = arr[n-1];
        for(int i = n-2; i >=0 ; i--) {
            right[i] =  max(arr[i] , right[i+1]);
        }
        
        int i = 0 , j = 0;
        while(j < n && i < n ) {
            if(left[i] <= right[j]) {
                maxi = max(maxi , j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends