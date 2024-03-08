//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int arr[26] = {0};
        for(auto i:s) arr[i-'a']++;
        int cntx = 0, cnty = 0;
        int x = -1, y = -1;
        for(int i = 0; i < 26; i++){
            if(arr[i] == 0) continue;
            if(x != arr[i] && y != arr[i] && x != -1 && y != -1){
                return false;
            }
            else{
                if(x == -1 || x == arr[i]){
                    x = arr[i];
                    cntx++;
                } else if(y == -1 && x != arr[i] || y == arr[i]){
                    y = arr[i];
                    cnty++;
                }
            }
        }
        if(cnty == 1 && y == 1 || cntx == 1 && x == 1 || cnty == 0 || x == 1 || y == 1) return true;
        if(cnty == 1 && y - x == 1) return true;
        if(cnty == 1 && y - x != 1) return false;
        if(cntx == 1 && x - y == 1) return true;
        if(cntx == 1 && x - y != 1) return false;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends