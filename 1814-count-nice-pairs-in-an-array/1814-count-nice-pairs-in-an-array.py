class Solution {
    public int countNicePairs(int[] nums) {
        int[] arr = new int[nums.length];
        for(int i=0; i<nums.length; i++) arr[i] = nums[i] - rev(nums[i]);
        Map<Integer, Integer> mp = new HashMap();
        int ans = 0, mod = (int)1e9+7;
        for(int x : arr){
            ans = (ans + mp.getOrDefault(x, 0)) % mod;
            mp.put(x, mp.getOrDefault(x, 0)+1);
        }
        return ans;
    }
    int rev(int num){
        int res = 0;
        while(num > 0){
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
}