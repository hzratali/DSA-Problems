//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int r1 = 0, r2 = n-1, c1 = 0, c2 = m-1;
 		while(true){
 		    for(int j=c1; j<=c2; j++){
 		        if(!--k) return a[r1][j];
 		    }
 		    r1++;
 		    for(int i=r1; i<=r2; i++){
 		        if(!--k) return a[i][c2];
 		    }
 		    c2--;
 		    for(int j=c2; j>=c1; j--){
 		        if(!--k) return a[r2][j];
 		    }
 		    r2--;
 		    for(int i=r2; i>=r1; i--){
 		        if(!--k) return a[i][c1];
 		    }
 		    c1++;
 		}
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends