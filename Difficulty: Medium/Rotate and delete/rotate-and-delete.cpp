//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int k = 1;  // kth element to delete from the last
        while(arr.size() > 1){
            // Step 1: Right rotate the array (clockwise by 1)
            int lastElement = arr.back();
            arr.pop_back();
            arr.insert(arr.begin(), lastElement);  // Insert the last element at the front
            // Step 2: Delete the kth element from the end
            int deleteIndex = arr.size() - k;
            if (deleteIndex < 0) {
                deleteIndex = 0;  // Safeguard in case index goes negative
            }
            arr.erase(arr.begin() + deleteIndex);
            // Increment k for the next deletion round
            k++;
        }
        // Return the last remaining element
        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends