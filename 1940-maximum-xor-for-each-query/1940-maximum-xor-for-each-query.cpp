class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXor(n);
        prefixXor[0] = nums[0];
        for(int i=1; i<n; i++) prefixXor[i] = prefixXor[i-1] ^ nums[i];
        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;
        for(int i=0; i<n; i++){
            int currXOR = prefixXor[n-1-i];
            ans[i] = currXOR ^ mask;
        }
        return ans;
    }
};