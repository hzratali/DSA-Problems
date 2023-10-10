class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = n;
        HashSet<Integer> st = new HashSet<>();
        for(int x : nums) st.add(x);
        int[] arr = new int[st.size()];
        int in = 0;
        for(int x : st) arr[in++] = x;
        Arrays.sort(arr);
        for(int i=0; i<arr.length; i++){
            int l = arr[i];
            int r = l+n-1;
            int j = upperBound(arr, r);
            int cnt  = j-i;
            ans = Math.min(ans, n-cnt);
        }
        return ans;
    }
    int upperBound(int[] arr, int target){
        int l=0, r = arr.length;
        while(l<r){
            int m = (l+r)/2;
            if(target < arr[m]) r = m;
            else l = m+1;
        }
        return l;
    }
}