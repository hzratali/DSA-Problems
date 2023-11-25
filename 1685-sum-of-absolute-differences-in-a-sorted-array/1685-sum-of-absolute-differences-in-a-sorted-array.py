class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length, totalSum = 0;
        for(int x : nums) totalSum += x;
        int leftSum = 0;
        int[] ans = new int[n];
        for(int i=0; i<n; i++){
            int rightSum = totalSum - leftSum - nums[i];
            
            int rightCnt = n-1-i, leftCnt = i;
            
            int leftTotal = leftCnt*nums[i] - leftSum;
            int rightTotal = rightSum - rightCnt*nums[i];
            
            ans[i] = leftTotal + rightTotal;
            leftSum += nums[i];
        }
        return ans;
    }
}