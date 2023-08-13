class Solution {
public:
    bool validPartition(vector<int>& nums) {
        map<int, bool> dp;
        dp[-1] = true;
        return f(nums.size()-1, nums, dp);
    }
    bool f(int i, vector<int>&nums, map<int, bool> &dp){
        if(dp.find(i) != dp.end()) return dp[i];
        bool ans = false;
        if(i>0 && nums[i]==nums[i-1]) ans |= f(i-2, nums, dp);
        if(i>1 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2]){
            ans |= f(i-3, nums, dp);
        }
        if(i>1 && nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1){
            ans |= f(i-3, nums, dp);
        }
        dp[i] = ans;
        return ans;
    }
};