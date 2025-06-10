class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        int oddCnt = 1, evenCnt = s.size();
        for(int x : freq){
            if(x == 0) continue;
            if(x % 2 == 1) oddCnt = max(oddCnt, x);
            else evenCnt = min(evenCnt, x);
        }
        return oddCnt-evenCnt;
    }
};