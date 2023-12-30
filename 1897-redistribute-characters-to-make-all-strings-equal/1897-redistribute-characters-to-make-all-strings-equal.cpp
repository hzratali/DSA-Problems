class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> cnt;
        for(string word : words){
            for(char c : word) cnt[c]++;
        }
        int n = words.size();
        for(auto &[key, val] : cnt){
            if(val % n != 0) return false;
        }
        return true;
    }
};