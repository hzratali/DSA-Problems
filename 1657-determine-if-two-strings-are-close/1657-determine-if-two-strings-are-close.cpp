class Solution {
public:
    bool closeStrings(string word1, string word2){
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for(char c : word1) cnt1[c-'a']++;
        for(char c : word2) cnt2[c-'a']++;
        for(int i=0; i<26; i++){
            if((cnt1[i]==0 && cnt2[i]!=0) || (cnt1[i]!=0 && cnt2[i]==0)) return false;
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        for(int i=0; i<26; i++){
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};