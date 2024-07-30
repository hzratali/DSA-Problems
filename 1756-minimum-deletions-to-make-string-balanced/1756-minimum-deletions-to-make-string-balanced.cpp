class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> cntA(n, 0);
        int aCnt = 0;
        //First pass: compute count a which store the number of a char to the right of the curr pos
        for(int i=n-1; i>=0; i--){
            cntA[i] = aCnt;
            if(s[i] == 'a') aCnt++;
        }
        int mnDel = n, bCnt = 0;
        //Second Pass: comupte minimum deletions on the fly
        for(int i=0; i<n; i++){
            mnDel = min(mnDel, bCnt+cntA[i]);
            if(s[i] == 'b') bCnt++;
        }
        return mnDel;
    }
};