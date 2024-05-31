//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int num=0;
        for(int i=0;i<8;i++){
            //first check which bit is set
            if(n& 1<<i){
                //if it is set then find its new position in num
                int position=(4+i)%8;
                //now set this position in num
                num=num | (1<<position);
            }
        }
        return num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends