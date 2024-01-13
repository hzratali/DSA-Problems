class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26, 0);
        for(int i=0; i<s.size(); i++){
            cnt[t[i]-'a']++;
            cnt[s[i]-'a']--;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            ans += max(0, cnt[i]);
        }
        return ans;
    }
};