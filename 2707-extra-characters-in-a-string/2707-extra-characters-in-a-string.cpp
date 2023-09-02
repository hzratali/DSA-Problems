class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dicSet(dictionary.begin(), dictionary.end());
        unordered_map<int, int> dp;
        return f(0, n, s, dicSet, dp);
    }
    int f(int start, int n, string &s, unordered_set<string> &dicSet, unordered_map<int, int> &dp){
        if(start == n) return 0;
        if(dp.count(start)) return dp[start];
        int ans = f(start+1, n, s, dicSet, dp) + 1;
        for(int r = start; r<n; r++){
            auto curr = s.substr(start, r-start+1);
            if(dicSet.count(curr)) ans = min(ans, f(r+1, n, s, dicSet, dp));
        }
        return dp[start] = ans;
    }
};