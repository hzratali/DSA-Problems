class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        while(k-- != 0){
            int mnIndex = 0;
            for(int i=0; i<nums.length; i++){
                if(nums[i] < nums[mnIndex]) mnIndex = i;
            }
            nums[mnIndex] *= multiplier;
        }
        return nums;
    }
}