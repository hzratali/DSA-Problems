//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int cnt = 0;
        for(int i=4; i<=n; i++){
            if(digit(i) == 4) cnt++;
        }
        return cnt;
    }
    int digit(int n){
        int rem = 0;
        while(n != 0){
            rem = n%10;
            if(rem==4) break;
            n = n/10;
        }
        return rem;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends