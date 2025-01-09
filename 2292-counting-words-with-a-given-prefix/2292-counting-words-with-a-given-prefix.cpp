class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(string &word : words) cnt += f(word, pref);
        return cnt;
    }
    int f(string &str, string &pref){
        int i;
        for(i=0; i<str.size() && i<pref.size(); i++){
            if(str[i] != pref[i]) return 0;
        }
        if(i != pref.size()) return 0;
        return 1;
    }
};