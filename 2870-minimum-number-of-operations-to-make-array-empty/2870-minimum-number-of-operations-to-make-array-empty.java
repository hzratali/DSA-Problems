class Solution {
    public int minOperations(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap();
        for(int x : nums) mp.put(x, mp.getOrDefault(x, 0)+1);
        int ans = 0;
        for(int cnt : mp.values()){
            if(cnt == 1) return -1;
            ans += Math.ceil((double)cnt/3);
        }
        return ans;
    }
}