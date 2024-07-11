//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int x[4]={-1, 0, 1, 0};
    int y[4]={0, 1, 0, -1};
    void grouper(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m, int group, int& size){
        if(i==n || i<0 || j==m || j<0 || vis[i][j]!=-1 || grid[i][j]==0){
            return;
        }
        vis[i][j]=group;
        size++;
        for(int k=0; k<4; ++k){
            int new_i=i+x[k];
            int new_j=j+y[k];
            grouper(grid, vis, new_i, new_j, n, m, group, size);
        }
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int maxSize=0, tempSize=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int size, group=0;
        unordered_map<int, int> mp;
        unordered_set<int> set;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    size=0;
                    grouper(grid, vis, i, j, n, m, group, size);
                    mp[group]=size;
                    maxSize=max(maxSize, size);
                    group++;
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==0){
                    tempSize=0;
                    for(int k=0; k<4; ++k){
                        int new_i=i+x[k];
                        int new_j=j+y[k];
                        if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && vis[new_i][new_j]!=-1 && !set.count(vis[new_i][new_j])){
                            tempSize+=mp[vis[new_i][new_j]];
                            set.insert(vis[new_i][new_j]);
                        }
                    }
                    maxSize=max(maxSize, tempSize+1);
                    set.clear();
                }
            }
        }
        return maxSize;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends