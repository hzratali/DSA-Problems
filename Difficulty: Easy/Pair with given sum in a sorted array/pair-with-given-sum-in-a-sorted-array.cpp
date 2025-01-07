//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int ans = 0;
        unordered_map<int, int> mp;
        for(int x : arr) mp[x]++;
        for(int i=0; i<arr.size(); i++){
            if(mp[target-arr[i]] != 0){
                if(arr[i] == target-arr[i]) ans += mp[target-arr[i]] - 1;
                else ans += mp[target-arr[i]];
            }
        }
        return ans/2;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends