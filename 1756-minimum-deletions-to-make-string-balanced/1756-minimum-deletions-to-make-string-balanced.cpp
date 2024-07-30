class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), a = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'a') a++;
        }
        int mnDel=n, b =0;
        for(int i=0; i<n; i++){
            if(s[i] == 'a') a--;
            mnDel = min(mnDel, a+b);
            if(s[i] == 'b') b++;
        }
        return mnDel;
    }
};