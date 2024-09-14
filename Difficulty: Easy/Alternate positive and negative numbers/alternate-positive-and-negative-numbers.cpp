//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos, neg;
        int a=0, b=0;
        for(int x : arr) (x>=0) ? pos.push_back(x) : neg.push_back(x);
        for(int i=0; i<arr.size(); i++){
            if(i%2==0){
                if(a<pos.size()) arr[i] = pos[a++];
                else arr[i] = neg[b++];
            }
            else{
                if(b<neg.size()) arr[i] = neg[b++];
                else arr[i] = pos[a++];
            }
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends