//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int buy1=INT_MIN, sell1=0, buy2=INT_MIN, sell2=0;
            for(int x : price){
                buy1 = max(buy1, -x);
                sell1 = max(sell1, buy1+x);
                buy2 = max(buy2, sell1-x);
                sell2 = max(sell2, buy2+x);
            }
            return sell2;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends