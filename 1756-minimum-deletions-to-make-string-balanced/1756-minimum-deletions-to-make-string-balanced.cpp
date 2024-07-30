class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> cntA(n, 0), cntB(n, 0);
        int bCnt = 0;
        //First pass: compute count b which store the number of b char to the left of the curr pos
        for(int i=0; i<n; i++){
            cntA[i] = bCnt;
            if(s[i] == 'b') bCnt++;
        }
        int aCnt = 0;
        //Second pass: compute count a which store the number of a char to the right of the curr pos
        for(int i=n-1; i>=0; i--){
            cntB[i] = aCnt;
            if(s[i] == 'a') aCnt++;
        }
        int mnDel = n;
        //Third Pass: Iterate through the string to find the minimum del
        for(int i=0; i<n; i++) mnDel = min(mnDel, cntA[i]+cntB[i]);
        return mnDel;
    }
};