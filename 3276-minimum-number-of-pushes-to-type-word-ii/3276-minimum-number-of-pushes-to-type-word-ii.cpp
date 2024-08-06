class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word) freq[c-'a']++;
        //Sort freq in desending order
        sort(freq.rbegin(), freq.rend());
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(freq[i] == 0) break;
            cnt += (i/8+1) * freq[i];
        }
        return cnt;
    }
};