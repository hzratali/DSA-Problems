//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat){
        //Your code here
        int r=0, c=0, n = mat.size(), cnt = 0;
        vector<int> ans;
        while(cnt < n*n){
            ans.push_back(mat[r][c]);
            cnt++;
            if(cnt >= n*n) break;
            if(c+1 < n) c++;
            else r++;
            while(r<n-1 && c>0){
                ans.push_back(mat[r][c]);
                cnt++;
                r++;
                c--;
            }
            ans.push_back(mat[r][c]);
            cnt++;
            if(r+1 < n) r++;
            else c++;
            while(r > 0 && c < n-1){
                ans.push_back(mat[r][c]);
                cnt++;
                r--;
                c++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends