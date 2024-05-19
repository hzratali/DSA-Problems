//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int resInd = 0;
        int val = abs(k-arr[0]);
        for(int i=1; i<n; i++){
            int diff = abs(k - arr[i]);
            if(diff < val || (diff==val && arr[i] > arr[resInd])){
                val = diff;
                resInd = i;
            }
        }
        return arr[resInd];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends