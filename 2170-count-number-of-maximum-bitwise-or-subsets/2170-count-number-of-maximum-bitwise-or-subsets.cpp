class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mxOrVal = 0;
        for(int x : nums) mxOrVal |= x;
        vector<vector<int>> dp(nums.size(), vector<int>(mxOrVal+1, -1));
        return cntSubSets(0, 0, mxOrVal, nums, dp);
    }
    int cntSubSets(int i, int currOrVal, int targetOrVal, vector<int> &nums, vector<vector<int>> &dp){
        // Base case: reached the end of the array
        if(i == nums.size()) return (currOrVal == targetOrVal) ? 1 : 0;
        //Check if the result is already memoized
        if(dp[i][currOrVal] != -1) return dp[i][currOrVal];
        //Don't include the curr number
        int notTake = cntSubSets(i+1, currOrVal, targetOrVal, nums, dp);
        //Include the curr number
        int take = cntSubSets(i+1, currOrVal|nums[i], targetOrVal, nums, dp);
        // return the sum of both cases
        return dp[i][currOrVal] = take+notTake;
    }
};