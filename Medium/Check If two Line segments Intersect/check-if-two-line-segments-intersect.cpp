//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long orient(int p[] , int q[] , int r[]){
        long val=(q[1]-p[1]+0l)*(r[0]-q[0]+0l)-(r[1]-q[1]+0l)*(q[0]-p[0]+0l);
        if(val==0) return 0;
        return (val>0)?1:2;
    }
    bool onseg(int a[] , int b[] , int c[]){
        if (c[0] >= min(a[0], b[0]) && c[0] <= max(a[0], b[0]) && c[1] >= min(a[1], b[1]) && c[1] <= max(a[1], b[1]))
        return true;
        return false;
    }
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        long o1=orient(p1,q1,p2);
        long o2=orient(p1,q1,q2);
        long o3=orient(p2,q2,p1);
        long o4=orient(p2,q2,q1);
        if(o1!=o2 &&  o3!=o4) return "true";
        if(o1==0 && onseg(p1,q1,p2)==true) return "true";
        if(o2==0 && onseg(p1,q1,q2)==true) return "true";
        if(o3==0 && onseg(p2,q2,p1)==true) return "true";
        if(o4==0 && onseg(p2,q2,q1)==true) return "true";
        return "false";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends