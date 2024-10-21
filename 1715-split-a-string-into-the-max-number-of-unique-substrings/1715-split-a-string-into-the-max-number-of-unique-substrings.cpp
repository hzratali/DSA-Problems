class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
    int backtrack(int i, string &s, unordered_set<string> &seen){
        if(i == s.size()) return 0;
        int mxCnt = 0;
        for(int j=i+1; j<=s.size(); j++){
            string subS = s.substr(i, j-i);
            if(seen.find(subS) == seen.end()){
                seen.insert(subS);
                mxCnt = max(mxCnt, 1+backtrack(j, s, seen));
                seen.erase(subS);
            }
        }
        return mxCnt;
    }
};