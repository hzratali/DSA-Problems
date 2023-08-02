//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0) return -1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        vector<vector<int>> vis(N, vector<int>(M, 0));
        vis[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first, j = q.front().second; q.pop();
                if(i == X && j == Y) return ans;
                for(int k=0; k<4; k++){
                    int row = i+dx[k], col = j+dy[k];
                    if(row>=0 && row<N && col>=0 && col<M && vis[row][col]==0 && A[row][col] == 1){
                        q.push({row, col});
                        vis[row][col] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends