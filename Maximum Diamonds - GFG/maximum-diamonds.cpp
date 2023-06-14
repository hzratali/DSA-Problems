//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int k) {
        // code here
        long long int ans = 0;
        priority_queue<int>pq;
        for(int i=0 ; i<N ; i++){
            pq.push(A[i]);
        }
        while(k>0){
            ans += pq.top();
            int t=pq.top()/2;
            pq.pop();
            pq.push(t);
            k--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends