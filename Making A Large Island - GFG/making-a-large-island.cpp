//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        unordered_map<int, int> mp;
        int id = 2, n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int cnt = 1;
                    dfs(grid, i, j, id, cnt);
                    mp[id] = cnt;
                    id++;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    set<int> s;
                    int sum = 1;
                    if(check(i-1, j, n, m) && s.find(grid[i-1][j])==s.end()){
                        sum += mp[grid[i-1][j]];
                        s.insert(grid[i-1][j]);
                    }
                    if(check(i, j-1, n, m) && s.find(grid[i][j-1])==s.end()){
                        sum += mp[grid[i][j-1]];
                        s.insert(grid[i][j-1]);
                    }
                    if(check(i+1, j, n, m) && s.find(grid[i+1][j])==s.end()){
                        sum += mp[grid[i+1][j]];
                        s.insert(grid[i+1][j]);
                    }
                    if(check(i, j+1, n, m) && s.find(grid[i][j+1])==s.end()){
                        sum += mp[grid[i][j+1]];
                        s.insert(grid[i][j+1]);
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans == INT_MIN ? n*m : ans;
    }
    void dfs(vector<vector<int>>&grid, int r, int c, int id, int &cnt){
        grid[r][c] = id;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int k=0; k<4; k++){
            int nr = r+dx[k], nc = c+dy[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                cnt++;
                dfs(grid, nr, nc, id, cnt);
            }
        }
    }
    bool check(int r, int c, int n, int m){
        if(r>=0 && r<n && c>=0 && c<m) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends