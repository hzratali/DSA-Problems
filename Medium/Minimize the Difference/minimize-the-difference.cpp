//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> premax(n),premin(n),suffmax(n),suffmin(n);
        premax[0]=arr[0];
        premin[0]=arr[0];
        for(int i=1;i<n;i++){
            premax[i]=max(arr[i],premax[i-1]);
            premin[i]=min(arr[i],premin[i-1]);
        }
        suffmax[n-1]=arr[n-1];
        suffmin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffmax[i]=max(arr[i],suffmax[i+1]);
            suffmin[i]=min(arr[i],suffmin[i+1]);
        }
        int res=INT_MAX;
        
        res=min(res,(suffmax[k]-suffmin[k]));
        
        for(int i=1;i<n-k;i++){
           res=min(res,max(premax[i-1],suffmax[i+k])-min(premin[i-1],suffmin[i+k])); 
        }
       
        res=min(res,premax[n-k-1]-premin[n-k-1]);
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends