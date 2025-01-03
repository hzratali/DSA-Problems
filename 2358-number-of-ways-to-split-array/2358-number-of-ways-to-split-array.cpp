class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long rightSum=0, leftSum=0;
        for(int x : nums) rightSum += x;
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            if(leftSum >= rightSum) cnt++;
        }
        return cnt;
    }
};