class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        if(s.size() == k) return true;
        vector<int> freq(26);
        for(auto &ch : s) freq[ch-'a']++;
        int oddCnt = 0;
        for(int i=0; i<26; i++){
            if(freq[i]%2 == 1) oddCnt++;
        }
        return oddCnt<=k;
    }
};