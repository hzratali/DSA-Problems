class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for(auto row : matrix){
            string pattern = "";
            for(int j=0; j<row.size(); j++){
                if(row[0] == row[j]) pattern += "T";
                else pattern += "F";
            }
            mp[pattern]++;
        }
        int mxFreq = 0;;
        for(auto &entry : mp) mxFreq = max(entry.second, mxFreq);
        return mxFreq;
    }
};