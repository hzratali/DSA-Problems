//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l = firstOcc(arr, 0, n-1, x);
	    int r = secondOcc(arr, 0, n-1, x);
	    if(l==-1 || r==-1) return 0;
	    return r-l+1;
	}
	int firstOcc(int arr[], int l, int r,int target){
	    int ans = -1;
	    while(l <= r){
	        int mid = (l+r)/2;
	        if(arr[mid] == target){
	            ans = mid;
	            r = mid-1;
	        }
	        else if(arr[mid] > target){
	            r = mid-1;
	        }
	        else l = mid+1;
	    }
	    return ans;
	}
	int secondOcc(int arr[], int l, int r,int target){
	    int ans = -1;
	    while(l <= r){
	        int mid = (l+r)/2;
	        if(arr[mid] == target){
	            ans = mid;
	            l = mid+1;
	        }
	        else if(arr[mid] > target){
	            r = mid-1;
	        }
	        else l = mid+1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends