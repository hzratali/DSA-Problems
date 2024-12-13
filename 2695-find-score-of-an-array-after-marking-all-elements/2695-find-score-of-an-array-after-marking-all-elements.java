class Solution {
    public long findScore(int[] nums) {
        long ans = 0;
        int[][] sorted = new int[nums.length][2];
        boolean[] marked = new boolean[nums.length];
        for(int i=0; i<nums.length; i++){
            sorted[i][0] = nums[i];
            sorted[i][1] = i;
        }
        Arrays.sort(sorted, (a, b)-> a[0]-b[0]);
        for(int i=0; i<nums.length; i++){
            int num = sorted[i][0], index = sorted[i][1];
            if(!marked[index]){
                ans += num;
                marked[index] = true;
                if(index-1 >= 0) marked[index-1] = true;
                if(index+1 < nums.length) marked[index+1] = true;
            }
        }
        return ans;
    }
}