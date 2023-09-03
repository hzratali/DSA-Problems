//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            if(mat[i][0] == 'O'){
                mat[i][0] = '1';
                q.push({i, 0});
            }
            if(mat[i][m-1] == 'O'){
                mat[i][m-1] = '1';
                q.push({i, m-1});
            }
        }
        for(int i=1; i<m-1; i++){
            if(mat[0][i] == 'O'){
                mat[0][i] = '1';
                q.push({0, i});
            }
            if(mat[n-1][i] == 'O'){
                mat[n-1][i] = '1';
                q.push({n-1, i});
            }
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty()){
            auto node = q.front(); q.pop();
            int row = node.first;
            int col = node.second;
            mat[row][col] = '1';
            for(int k=0; k<4; k++){
                int r = row+dx[k];
                int c = col+dy[k];
                if(r>=0 && r<n && c>=0 && c<m && mat[r][c]=='O'){
                    q.push({r, c});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                if(mat[i][j] == '1') mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends