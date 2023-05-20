//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    bool flag = true;
                    dfs(matrix, i, j, n, m, flag);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &mat, int i, int j, int &n, int &m, bool &flag){
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]==0) return;
        if((i==0 || i==n-1) || (j==0 || j==m-1) && mat[i][j]==1) flag = false;
        mat[i][j] = 0;
        dfs(mat, i+1, j, n, m, flag);
        dfs(mat, i-1, j, n, m, flag);
        dfs(mat, i, j+1, n, m, flag);
        dfs(mat, i, j-1, n, m, flag);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends