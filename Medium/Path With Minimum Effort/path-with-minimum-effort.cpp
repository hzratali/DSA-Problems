//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        vector<vector<int>> dis(rows, vector<int> (columns, 1e9));
        set<pair<int, pair<int, int>>> s;
        s.insert({0, {0, 0}});
        dis[0][0] = 0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while(!s.empty()){
            int curr = s.begin()->first;
            int x = s.begin()->second.first, y = s.begin()->second.second;
            s.erase(s.begin());
            if(curr != dis[x][y]) continue;
            for(int k=0; k<4; k++){
                int nx = x+ dx[k], ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<rows && ny<columns && max(curr, abs(heights[nx][ny]-heights[x][y])) < dis[nx][ny]){
                    dis[nx][ny] = max(curr, abs(heights[nx][ny]-heights[x][y]));
                    s.insert({dis[nx][ny], {nx, ny}});
                }
            }
        }
        return dis[rows-1][columns-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends