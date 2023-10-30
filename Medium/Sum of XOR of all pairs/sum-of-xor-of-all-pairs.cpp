//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	long long int sum = 0;
    	for(int i=0; i<32; i++){
    	    long long int zc = 0, oc = 0;
    	    for(int j=0; j<n; j++){
    	        arr[j] % 2 == 0 ? zc++ : oc++;
    	        arr[j] /= 2;
    	    }
    	    sum += zc * oc * (1 << i);
    	}
    	return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends