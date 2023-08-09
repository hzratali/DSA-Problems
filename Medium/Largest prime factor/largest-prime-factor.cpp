//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(long long int N){
        // code here
        long long int mx = 0;
        for(long long int i=2; i*i<=N; i++){
            while(N%i == 0){
                mx = max(mx, i);
                N = N/i;
            }
        }
        if(N > 1) mx = max(mx, N);
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends