//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int prevx = 0, prevy = 0;
	    int lastx = n-1, lasty = n-1, cnt = 0;
	    while(prevx < n && prevy < n && lastx >= 0 && lasty>=0){
	        int sum = mat1[prevx][prevy] + mat2[lastx][lasty];
	        if(sum <= x){
	            if(sum == x) cnt++;
	            prevy++;
	            if(prevy == n){
	                prevy = 0;
	                prevx++;
	            }
	        }
	        else{
	            lasty--;
	            if(lasty<0){
	                lasty = n-1;
	                lastx--;
	            }
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends