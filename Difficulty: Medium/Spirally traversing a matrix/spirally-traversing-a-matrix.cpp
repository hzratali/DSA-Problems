//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int totalCell = n*m, cnt = 0;
        int rStart = 0, rEnd = n-1, cStart = 0, cEnd = m-1;
        while(cnt < totalCell){
            for(int i=cStart; cnt < totalCell && i<=cEnd; i++){
                ans.push_back(matrix[rStart][i]);
                cnt++;
            }
            rStart++;
            for(int i=rStart; cnt < totalCell && i<=rEnd; i++){
                ans.push_back(matrix[i][cEnd]);
                cnt++;
            }
            cEnd--;
            for(int i=cEnd; cnt < totalCell && i>=cStart; i--){
                ans.push_back(matrix[rEnd][i]);
                cnt++;
            }
            rEnd--;
            for(int i=rEnd; cnt < totalCell && i>=rStart; i--){
                ans.push_back(matrix[i][cStart]);
                cnt++;
            }
            cStart++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends