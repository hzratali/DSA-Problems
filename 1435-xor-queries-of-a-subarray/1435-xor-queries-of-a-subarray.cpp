class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &x : queries){
            int xr = arr[x[0]];
            for(int i=x[0]; i<x[1]; i++){
                xr ^= arr[i+1];
            }
            ans.push_back(xr);
        }
        return ans;
    }
};