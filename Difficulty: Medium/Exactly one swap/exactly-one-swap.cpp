class Solution {
  public:
    int countStrings(string &s) {
        // code here
        vector<int>freq(26, 0);
        int n = s.size();
        for(int i=0; i<n; i++) freq[s[i]-'a']++;
        int cnt = 0;
        bool flag = false;
        for(int i=0; i<n; i++){
            if(freq[s[i]-'a'] > 0) cnt += (n - freq[s[i]-'a']);
            if(freq[s[i]-'a'] > 1) flag = true;
        }
        cnt /= 2;
        return flag ? cnt+1 : cnt;
    }
};
