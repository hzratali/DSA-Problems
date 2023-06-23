//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        vector<int> f(26);
        int mx=0;
        //storing frequency of each word
        for(int i=0; i<N; i++){
            f[tasks[i]-'A']++;
            mx=max(mx,f[tasks[i]-'A']);
        }
        //answer depend upon the max frequency occured
        int ans=(K+1)*(mx-1);
        //if max frequency is equal for more than 1
        for(int i=0; i<26; i++){
            if(mx==f[i])ans++;
        }
        return max(ans, N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends