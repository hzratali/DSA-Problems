//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n = arr.size(), mx1 = 0, sum1 = 0, total = 0;
        for(int i=0; i<n; i++){
            sum1 += arr[i];
            total += arr[i];
            if(sum1 > mx1) mx1 = max(mx1, sum1);
            if(sum1 < 0) sum1 = 0;
        }
        int mx2 = 0, sum2 = 0;
        for(int i=0; i<n; i++){
            sum2 += arr[i];
            mx2 = min(mx2, sum2);
            if(sum2 > 0) sum2 = 0;
        }
        return max(mx1, total-mx2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends