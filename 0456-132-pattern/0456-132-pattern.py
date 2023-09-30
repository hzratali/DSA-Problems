class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> s = new Stack<>();
        int third  = Integer.MIN_VALUE;
        for(int i=nums.length-1; i>=0; i--){
            if(third > nums[i]) return true;
            while(!s.isEmpty() && s.peek() < nums[i]){
                third = s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
}