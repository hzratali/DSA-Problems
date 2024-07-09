//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n = arr.size(), mxSum = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-2; i++){
            int l=i+1, r=n-1;
            while(l < r){
                int sum = arr[i] + arr[l] + arr[r];
                if(sum == target) return sum;
                if(abs(target-sum) < abs(target-mxSum)) mxSum = sum;
                if(abs(target-sum) == abs(target-mxSum)) mxSum = max(mxSum, sum);
                if(sum > target) r--;
                else l++;
            }
        }
        return mxSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends