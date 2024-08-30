//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> result;
        vector<int> board(n, -1); // board[i] represents the row position of the queen in the ith column
        vector<bool> rows(n, false); // to check if a row is already occupied
        vector<bool> d1(2*n - 1, false); // to check the first diagonal (r - c)
        vector<bool> d2(2*n - 1, false); // to check the second diagonal (r + c)
        solve(0, n, board, rows, d1, d2, result);
        return result;
    }
    void solve(int col, int n, vector<int>& board, vector<bool>& rows, vector<bool>& d1, vector<bool>& d2, vector<vector<int>>& result) {
        if (col == n) {
            // All queens are placed successfully, add the solution to the result
            result.push_back(board);
            return;
        }
        for (int row = 0; row < n; ++row) {
            if (!rows[row] && !d1[row - col + n - 1] && !d2[row + col]) {
                // Place the queen
                board[col] = row + 1;
                rows[row] = d1[row - col + n - 1] = d2[row + col] = true;
                // Recurse for the next column
                solve(col + 1, n, board, rows, d1, d2, result);
                // Backtrack
                rows[row] = d1[row - col + n - 1] = d2[row + col] = false;
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends