class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != n*m) return {};
        vector<vector<int>> ans;
        for(int i=0; i<original.size(); i+=n){
            vector<int> ds;
            for(int j=0; j<n; j++){
                ds.push_back(original[i+j]);
            }
            ans.push_back(ds);
        }
        return ans;
    }
};