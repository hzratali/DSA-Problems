//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int i = arr.size()-1, carry =0, sum = 0;
        char ch;
        string str = "";
        while(i >= 0){
            sum = carry + arr[i--];
            if(i >= 0) sum += arr[i--];
            ch = ((sum%10) + '0');
            str += ch;
            carry = sum >= 10 ? 1 : 0;
        }
        if(carry) str += '1';
        reverse(str.begin(), str.end());
        i = 0;
        while(i < str.size() && str[i] == '0') i++;
        return i>=str.size() ? "0" : str.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends