class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<char> dp(n+1, 0);
        dp[0] = 1;
        for(int i=0; i<n; i++){
            int ind = i+1;
            if(i>0 && nums[i]==nums[i-1]) dp[ind] |= dp[ind-2];
            if(i>1 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2]) dp[ind] |= dp[ind-3];
            if(i>1 && nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1) dp[ind] |= dp[ind-3];
        }
        return dp[n];
    }
};