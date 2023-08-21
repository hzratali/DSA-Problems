//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size(), m = matrix[0].size(), count = 0;
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                int cnt = 0;
                if(matrix[i][j] == 1){
                    for(int k=0; k<8; k++){
                        int r = i+dx[k];
                        int c = j+dy[k];
                        if(r>=0 && r<n && c>=0 && c<m && matrix[r][c]==0) cnt++;
                    }
                }
                if(cnt > 0 && cnt%2==0) count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends