class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n+1, 0);
        for(int i=0; i<n; i++) prefixXOR[i+1] = prefixXOR[i] ^ arr[i];
        vector<int> ans;
        for(auto &x : queries){
            ans.push_back(prefixXOR[x[1]+1] ^ prefixXOR[x[0]]);
        }
        return ans;
    }
};