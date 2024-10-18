class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mxOrVal = 0;
        for(int x : nums) mxOrVal |= x;
        return cntSubSets(0, 0, mxOrVal, nums);
    }
    int cntSubSets(int i, int currOrVal, int targetOrVal, vector<int> &nums){
        // Base case: reached the end of the array
        if(i == nums.size()) return (currOrVal == targetOrVal) ? 1 : 0;
        //Don't include the curr number
        int notTake = cntSubSets(i+1, currOrVal, targetOrVal, nums);
        //Include the curr number
        int take = cntSubSets(i+1, currOrVal|nums[i], targetOrVal, nums);
        // return the sum of both cases
        return take+notTake;
    }
};