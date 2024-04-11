//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n){
        // Your code here
        if(n == 0) return 0;
        vector<int> binary;
        int num = n;
        while(num > 1){
            int bit = num%2;
            binary.push_back(bit);
            num /= 2;
        }
        binary.push_back(1);
        vector<int> grayCode;
        int m = binary.size()-1;
        grayCode.push_back(binary[m]);
        int temp = binary[m];
        m = m-1;
        while(m >= 0){
            temp ^= binary[m];
            grayCode.push_back(temp);
            m--;
        }
        m = grayCode.size();
        int ans = 0, i = m-1;
        while(i >= 0){
            temp = grayCode[i] * pow(2, m-i-1);
            ans += temp;
            i--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends