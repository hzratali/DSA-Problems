class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 1, r = nums.size(), mnLen = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(isValidSubArray(nums, k, m)){
                mnLen = m;
                r = m-1;
            }
            else l = m+1;
        }
        return mnLen;
    }
    bool isValidSubArray(vector<int>&nums, int targetSum, int windowSize){
        int arrLen = nums.size();
        vector<int> bitCnt(32, 0);
        for(int r=0; r<arrLen; r++){
            updateBitCnt(bitCnt, nums[r], 1);
            if(r >= windowSize) updateBitCnt(bitCnt, nums[r - windowSize], -1);
            if(r >= windowSize-1 && convertBitCountsToNumber(bitCnt) >= targetSum) return true;
        }
        return false;
    }
    void updateBitCnt(vector<int>& bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if (((number >> bitPosition) & 1) != 0) {
                bitCounts[bitPosition] += delta;
            }
        }
    }
    // Converts bit count array back to number using OR operation
    int convertBitCountsToNumber(vector<int>& bitCounts) {
        int number = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                number |= 1 << bitPosition;
            }
        }
        return number;
    }
};