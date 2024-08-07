//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n = arr1.size(), m = arr2.size(), lastElement = 0, i = 0, j =0;
        while(k){
            if(i >= n){
                lastElement = arr2[j++];
            }
            else if(j >= m){
                lastElement = arr1[i++];
            }
            else{
                if(arr1[i] > arr2[j]){
                    lastElement = arr2[j++];
                }
                else{
                    lastElement = arr1[i++];
                }
            }
            k--;
        }
        return lastElement;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends