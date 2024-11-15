class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int r = arr.length-1;
        while(r>0 && arr[r] >= arr[r-1]) r--;
        int ans = r, l = 0;
        while(l < r && (l==0 || arr[l-1]<=arr[l])){
            while(r<arr.length && arr[l]>arr[r]) r++;
            ans = Math.min(ans, r-l-1);
            l++;
        }
        return ans;
    }
}