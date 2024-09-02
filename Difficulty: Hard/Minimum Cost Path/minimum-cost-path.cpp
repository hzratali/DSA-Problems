//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int row = 0, col = 0, n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        vis[row][col]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{row,col}});
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int dist=pq.top().first;
            pq.pop();
            
            if(r==n-1 && c==n-1) return dist;
            
            for(int i=0;i<4;i++){
                
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc])
                {
                   vis[nr][nc]=1;
            
                   if(dis[nr][nc]>(dist+grid[nr][nc]))
                   
                   dis[nr][nc]=dist+grid[nr][nc];
                   
                   pq.push({dis[nr][nc],{nr,nc}});
                   
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends