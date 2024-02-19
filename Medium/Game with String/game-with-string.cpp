//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> cnt(26, 0);
        for(char c : s) cnt[c-'a']++;
        priority_queue<int> pq;
        for(int x : cnt) pq.push(x);
        while(k--){
            int n = pq.top(); pq.pop();
            pq.push(n-1);
        }
        int ans = 0;
        while(!pq.empty()){
            int x = pq.top(); pq.pop();
            ans += (x*x);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends