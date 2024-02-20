//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    vector<int>dp;
    vector<string> dictionary;
    string s;
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        dp = vector<int>(s.size(), -1);
        this->dictionary = dictionary;
        this->s = s;
        return f(0);
    }
    bool f(int i){
        if(i >= s.size()) return true;
        if(dp[i] != -1) return dp[i] == 1;
        for(string word : dictionary){
            int len = word.size();
            if(i+len-1 >= s.size()) continue;
            if(s.substr(i, len) == word && f(i+len)){
                dp[i] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends