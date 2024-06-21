//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        vector<float> v;
        string x;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='/' || str[i]==','){
                v.push_back(stoi(x));
                x = "";
            }
            else x += str[i];
        }
        v.push_back(stoi(x));
        int a = v[0], b = v[1], c = v[2], d = v[3];
        if(v[0]/v[1] > v[2]/v[3]) return to_string(a)+'/'+to_string(b);
        else if(v[0]/v[1] == v[2]/v[3]) return "equal";
        return to_string(c)+'/'+to_string(d);
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends